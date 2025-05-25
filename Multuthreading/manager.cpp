#include "manager.h"

Manager::Manager(QObject *parent)
    : QObject{parent}
{
    m_layout = new QVBoxLayout();
}

void Manager::setThreadsAmount(int amount)
{
    for (int index = 0; index < amount; index++) {
        TextParser *parser = new TextParser();

        // Adding graphics stuff

        QLabel *label = new QLabel();
        label->setText("Starting....");

        QProgressBar *progressBar = new QProgressBar();
        progressBar->setValue(0);
        progressBar->setRange(0, 100);

        m_layout->addWidget(label);
        m_layout->addWidget(progressBar);

        connect (parser, &TextParser::progress, progressBar, &QProgressBar::setValue);

        m_threads.push_back(parser);
    }
}

void Manager::start()
{
    qDebug() << "[Manager]: Text size is " << m_text.size();
    int textAmount = m_text.size() / m_threads.size();
    qDebug() << "[Manager]: Slice per thread is " << textAmount;
    QString textLeft = m_text;
    for (int currentIndex = 0; currentIndex < m_threads.size(); currentIndex++) {
        TextParser *parser = m_threads.at(currentIndex);
        parser->setCharset(m_charset);
        int lastSymbol = -1;
        if (currentIndex == m_threads.size() - 1)
            lastSymbol = m_text.size() - currentIndex * textAmount;
        else
            lastSymbol = textAmount;
        qDebug() << "Thread #" << currentIndex << ": " << currentIndex * textAmount << "/" << lastSymbol;
        QString textForThread = m_text.mid(currentIndex * textAmount, textAmount);
        qDebug() << "Thread #" << currentIndex << ": gonna serve " << textForThread.size() << " bytes";
        parser->setText(textForThread);
        parser->start();
    }
}
