#ifndef AIWORKER_H
#define AIWORKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>


class AiWorker : public QObject
{
    Q_OBJECT
public:
    explicit AiWorker(QObject *parent = nullptr);

public slots:
    void askAi(QString query);
    QString getAnswer() { return m_answer; }

private slots:
    void gotAnswer(QNetworkReply *reply);

signals:
    void answerReceieved();

private:
    QNetworkAccessManager *m_manager;
    QString m_answer;
};

#endif // AIWORKER_H
