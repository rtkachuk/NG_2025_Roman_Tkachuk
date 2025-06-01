#include "pasidelki.h"
#include "ui_pasidelki.h"

Pasidelki::Pasidelki(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Pasidelki)
{
    ui->setupUi(this);

    m_socket = new QTcpSocket();

    ui->stackedWidget->setCurrentIndex(0);

    ui->sb_port->setRange(1000, 65535);
    ui->te_chat->setReadOnly(true);

    connect (ui->b_login, &QPushButton::clicked, this, &Pasidelki::login);
    connect (ui->b_send, &QPushButton::clicked, this, &Pasidelki::sendMessage);

    connect (m_socket, &QTcpSocket::connected, this, &Pasidelki::connectionEstablished);
    connect (m_socket, &QTcpSocket::readyRead, this, &Pasidelki::messageReceived);
}

Pasidelki::~Pasidelki()
{
    delete ui;
    m_socket->disconnectFromHost();
    delete m_socket;
}

void Pasidelki::login()
{
    if (ui->le_login->text().isEmpty()) {
        ui->statusbar->showMessage("You have not entered the login!");
        return;
    }
    QString address = ui->le_address->text();
    int port = ui->sb_port->value();

    m_socket->connectToHost(QHostAddress(address), port);
}

void Pasidelki::connectionEstablished()
{
    QByteArray message = "LOGN";
    ui->stackedWidget->setCurrentIndex(1);
    m_socket->write(message + ui->le_login->text().toLocal8Bit());
}

void Pasidelki::sendMessage()
{
    QByteArray message = "MSSG";
    m_socket->write(message + ui->te_message->toPlainText().toLocal8Bit());
    ui->te_message->clear();
}

void Pasidelki::messageReceived()
{
    ui->te_chat->setPlainText(ui->te_chat->toPlainText() + QString(m_socket->readAll()));
}
