#pragma once

#include <QNetworkAccessManager>
#include <QObject>
#include <QNetworkReply>

#include "../dataTypes.hpp"

enum class Method
{
    POST = QNetworkAccessManager::Operation::PostOperation,
    PUT = QNetworkAccessManager::Operation::PutOperation,
    GET = QNetworkAccessManager::Operation::GetOperation,
    DEL = QNetworkAccessManager::Operation::DeleteOperation
};

class NetworkService : public QObject
{
    Q_OBJECT

public:
    NetworkService(QObject *parent = nullptr);

    virtual void sendRequest(QString endpoint,
                             const Method &method = Method::GET,
                             const Dataset &dataset = Dataset(),
                             const QString &id = "");

    void setApiUrl(const QString &api);

private slots:
    void onNetworkReply();

private:
    QNetworkAccessManager *m_manager;
    QString m_apiUrl;
};