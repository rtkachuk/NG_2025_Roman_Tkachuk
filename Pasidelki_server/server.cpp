#include "server.h"

Server::Server() {
    m_servak = new QTcpServer();

    connect (m_servak, &QTcpServer::newConnection, this, &Server::newClient);
}

Server::~Server()
{
    if (m_servak->isListening()) {
        log ("Stopping server...");
        m_servak->close();
    }

    delete m_servak;
}

bool Server::start(QString host, int port)
{
    bool ok = m_servak->listen(QHostAddress(host), port);
    if (ok)
        log ("Server listening at " + host + ":" + QString::number(port));
    else
        log ("Can't start the server: " + m_servak->errorString());
    return ok;
}

void Server::newClient()
{
    QTcpSocket *client = m_servak->nextPendingConnection();
    log ("Client connected: " + client->localAddress().toString());

    connect (client, &QTcpSocket::disconnected, this, &Server::leftClient);
    connect (client, &QTcpSocket::readyRead, this, &Server::messageFromClient);

    m_clients[client] = "Anon";
}

void Server::leftClient()
{
    QTcpSocket *client = (QTcpSocket *) sender();

    disconnect (client, &QTcpSocket::disconnected, this, &Server::leftClient);
    disconnect (client, &QTcpSocket::readyRead, this, &Server::messageFromClient);

    m_clients.remove(client);

    log ("Client disconnected: " + client->localAddress().toString());
}

void Server::sendToAll(QByteArray message)
{
    for (QTcpSocket *client : m_clients.keys()) {
        client->write(message);
    }
}

void Server::messageFromClient()
{
    QTcpSocket *client = (QTcpSocket *) sender();
    QByteArray nickname = "<<" + m_clients[client] + ">>";
    QByteArray rawData = client->readAll();

    QByteArray command = rawData.first(COMMAND_SIZE); // First 4 bytes of command
    QByteArray message = rawData.last(rawData.size() - COMMAND_SIZE);

    if (command == "LOGN") {
        log ("New user with login " + QString(message));
        m_clients[client] = message;
    }

    if (command == "MSSG") {
        sendToAll(nickname + ": " + message);
        log ("User " + nickname + " sent: " + message);
    }
}

void Server::log(QString message)
{
    qDebug() << "[" << QDateTime::currentDateTime().toString("hh:mm:ss.z") << "]: " << message;
}
