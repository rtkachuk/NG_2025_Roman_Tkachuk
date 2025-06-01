#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QDateTime>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server();
    ~Server();

public slots:
    bool start(QString host, int port);

private slots:
    void newClient();
    void leftClient();
    void sendToAll(QByteArray message);
    void messageFromClient();

private:
    void log(QString message);

    QTcpServer *m_servak = nullptr;
    QMap<QTcpSocket *, QByteArray> m_clients;

    const int COMMAND_SIZE = 4;

};

#endif // SERVER_H
