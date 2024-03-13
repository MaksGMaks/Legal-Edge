#include <iostream>

#include <QCoreApplication>
// #include <QNetworkAccessManager>
// #include <QNetworkRequest>
// #include <QNetworkReply>
// #include <QDebug>
#include "network/NetworkService.hpp"

#include <chrono>
#include <thread>
#include <boost/asio.hpp>
#include <boost/beast.hpp>

namespace a = boost::asio;
namespace http = boost::beast::http;

const QString SERVER_API_URL{"http://127.0.0.1:8080/api"};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NetworkService network(nullptr);
    network.setApiUrl(SERVER_API_URL);
    Dataset dataset;
    dataset["data"] = {"Test Network with QNETWORKACCESSMANAGER"};
    network.sendRequest("", Method::POST, dataset);
    return a.exec();
}