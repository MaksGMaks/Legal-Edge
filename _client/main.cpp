#include <iostream>

#include <QCoreApplication>
#include "network/ApiManager.hpp"
#include "network/JsonSerializer.hpp"

// for test
#include <QThread>
#include <thread>
#include <chrono>

const QString SERVER_API_URL{"http://127.0.0.1:8080/api"};

void DOWORK()
{
    qDebug() << "DOWORK";
}

class MyThread : public QThread
{
private:
    NetworkService *network;
    ApiManager *api;

public:
    MyThread()
    {
        network = new NetworkService(nullptr);
        network->setApiUrl(SERVER_API_URL);
        network->setSerializer(std::make_unique<JsonSerializer>());
        api = new ApiManager(*network);
    }

public:
    void run() override
    {
        api->loginUser("admin2", "admin2");
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NetworkService net(nullptr);
    net.setApiUrl(SERVER_API_URL);
    net.setSerializer(std::make_unique<JsonSerializer>());
    ApiManager api(net);
    api.loginUser("admin2", "admin2");
    qDebug() << "sleeping";
    DOWORK();

    qDebug() << "attempt no 2";
    api.addNewCustomer("bro", "0973333");

    qDebug() << "attempt no 3";
    api.registerUser("dada", "dawda");
    return a.exec();
}