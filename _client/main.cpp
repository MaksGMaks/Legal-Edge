#include <iostream>

#include <QCoreApplication>
// #include <QNetworkAccessManager>
// #include <QNetworkRequest>
// #include <QNetworkReply>
// #include <QDebug>
#include "network/ApiManager.hpp"

const QString SERVER_API_URL{"http://127.0.0.1:8080/api"};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NetworkService network(nullptr);
    network.setApiUrl(SERVER_API_URL);
    ApiManager api(network);
    api.loginUser("admin", "1234234");
    return a.exec();
}