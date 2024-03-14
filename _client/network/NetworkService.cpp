#include "NetworkService.hpp"

#include "../Endpoints.hpp"

#include <qDebug>
#include <QByteArray>

NetworkService::NetworkService(QObject *parent) : QObject(parent), m_manager(new QNetworkAccessManager(this))
{
    qDebug() << "NetworkService::NetworkService";
}
void NetworkService::sendRequest(QString endpoint, const Method &method, const Dataset &dataset, const QString &id)
{
    /*serialaizer if()*/
    qDebug() << "url";
    QUrl fulUrl = m_apiUrl + "/" + id;
    QNetworkRequest request(fulUrl);

    qDebug() << "reply";
    QNetworkReply *reply = nullptr;
    /*serialize data*/
    QString str = dataset[Keys::User::USERNAME][0] + " " + dataset[Keys::User::PASSWORD][0];
    QByteArray byteArr = str.toUtf8();
    qDebug() << "swich";
    switch (method)
    {
    case Method::GET:
        reply = m_manager->get(request);
        break;
    case Method::POST:
        reply = m_manager->post(request, byteArr);
        break;
    case Method::PUT:
        reply = m_manager->put(request, byteArr);
        break;
    case Method::DEL:
        reply = m_manager->deleteResource(request);
        break;
    default:
        qDebug() << "wrong in swich-case sengrequest";
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

void NetworkService::onNetworkReply(const QString &endpoint, const Method &method, QNetworkReply *reply)
{
    qDebug() << "tuta";
}