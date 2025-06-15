#ifndef WHISPER_H
#define WHISPER_H

#include <QMainWindow>
#include "aiworker.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Whisper;
}
QT_END_NAMESPACE

class Whisper : public QMainWindow
{
    Q_OBJECT

public:
    Whisper(QWidget *parent = nullptr);
    ~Whisper();

public slots:
    void sendToAi();
    void answerReceived();

private:
    Ui::Whisper *ui;
    AiWorker *m_ai;
};
#endif // WHISPER_H
