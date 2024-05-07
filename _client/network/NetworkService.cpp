#include "NetworkService.hpp"

#include "../Endpoints.hpp"

#include <qDebug>
#include <QByteArray>
#include <thread>
#include <chrono>

NetworkService::NetworkService(QObject *parent) : QObject(parent), m_manager(new QNetworkAccessManager(this))
{
    qDebug() << "NetworkService::NetworkService";
}
void NetworkService::sendRequest(QString endpoint, const Method &method, const Dataset &dataset, const QString &id)
{
    if (!m_serializer)
    {
        qDebug() << "m_serializer not set";
    }
    QUrl fulUrl = m_apiUrl + endpoint + "/" + id;
    QNetworkRequest request(fulUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, QNetworkRequest::ManualRedirectPolicy);
    qDebug() << "reply";
    QNetworkReply *reply = nullptr;
    auto dataToSend = m_serializer->serialize(dataset);
    switch (method)
    {
    case Method::GET:
        reply = m_manager->get(request);
        break;
    case Method::POST:
        reply = m_manager->post(request, dataToSend);
        break;
    case Method::PUT:
        reply = m_manager->put(request, dataToSend);
        break;
    case Method::DEL:
        reply = m_manager->deleteResource(request);
        break;
    default:
        qDebug() << "wrong in swich-case sendrequest";
        break;
    }
    qDebug() << "if";
    if (reply != nullptr)
    {
        qDebug() << "vrodi tuta";
        connect(reply, &QNetworkReply::finished, this, [this, endpoint = std::move(endpoint), method, reply]
                { this->onNetworkReply(endpoint, method, reply); });
    }
    else
    {
        qDebug() << "ne tuta";
    }
}

void NetworkService::setApiUrl(const QString &api)
{
    m_apiUrl = api;
}

void NetworkService::setSerializer(std::unique_ptr<IDataSerializer> serializer)
{
    m_serializer = std::move(serializer);
}

void NetworkService::onNetworkReply(const QString &endpoint, const Method &method, QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        qDebug() << "tuta";
        QByteArray data = reply->readAll();
        auto dataset = m_serializer->deserialize(data);
        qDebug() << dataset[Keys::Notes::TEXT];
    }
    else
    {
        qDebug() << "Error - " << reply->error();
    }
    reply->deleteLater();
}