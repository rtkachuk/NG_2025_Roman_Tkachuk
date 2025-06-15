#include "aiworker.h"

AiWorker::AiWorker(QObject *parent)
    : QObject{parent}
{
    m_manager = new QNetworkAccessManager();

    connect (m_manager, &QNetworkAccessManager::finished, this, &AiWorker::gotAnswer);
}

void AiWorker::askAi(QString query)
{
    QNetworkRequest request(QUrl("http://localhost:11434/api/generate"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;

    json["model"] = "llama3.2";
    json["prompt"] = query;
    json["stream"] = false;

    m_manager->post(request, QJsonDocument(json).toJson());
}

void AiWorker::gotAnswer(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray textReply = reply->readAll();
        m_answer = QJsonDocument::fromJson(textReply).object().value("response").toString();
        emit answerReceieved();
    } else {
        qDebug() << "[Ai Worker]: Error " << reply->errorString();
    }
}
