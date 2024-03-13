#pragma once

#include <QNetworkAccessManager>

#include <QObject>
<<<<<<< HEAD
#include <QNetworkReply>

#include "../dataTypes.hpp"
=======
#include <QHash>
#include <QStringList>
#include <QNetworkReply>

using Data = QStringList;
using Dataset = QMap<QString, Data>;
>>>>>>> 8fe4822 (network worked correctly (#3))

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
<<<<<<< HEAD
    void onNetworkReply(const QString &endpoint, const Method &method, QNetworkReply *reply);
=======
    void onNetworkReply();
>>>>>>> 8fe4822 (network worked correctly (#3))

private:
    QNetworkAccessManager *m_manager;
    QString m_apiUrl;
};