#ifndef PASIDELKI_H
#define PASIDELKI_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class Pasidelki;
}
QT_END_NAMESPACE

class Pasidelki : public QMainWindow
{
    Q_OBJECT

public:
    Pasidelki(QWidget *parent = nullptr);
    ~Pasidelki();

private slots:
    void login();
    void connectionEstablished();
    void sendMessage();
    void messageReceived();

private:
    Ui::Pasidelki *ui;
    QTcpSocket *m_socket;
};
#endif // PASIDELKI_H
