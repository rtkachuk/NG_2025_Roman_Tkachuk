#include "whisper.h"
#include "ui_whisper.h"

Whisper::Whisper(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Whisper)
{
    ui->setupUi(this);
    ui->te_aiOutput->setReadOnly(true);

    m_ai = new AiWorker(this);

    connect (ui->b_ask, &QPushButton::clicked, this, &Whisper::sendToAi);
    connect (m_ai, &AiWorker::answerReceieved, this, &Whisper::answerReceived);
}

Whisper::~Whisper()
{
    delete ui;
}

void Whisper::sendToAi()
{
    m_ai->askAi(ui->te_userInput->toPlainText());
}

void Whisper::answerReceived()
{
    ui->te_aiOutput->setText(m_ai->getAnswer());
}
