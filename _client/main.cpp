#include <iostream>

#include <QCoreApplication>
#include <QApplication>
#include "network/ApiManager.hpp"
#include "network/JsonSerializer.hpp"

#include "Ui/UiManager.hpp"
#include "LegalEdgeClient.hpp"

// for test
#include <QThread>
#include <thread>
#include <chrono>

const QString SERVER_API_URL{"http://127.0.0.1:8080/api"};

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
    // Network setup
    QApplication app(argc, argv);
    NetworkService net(nullptr);
    net.setApiUrl(SERVER_API_URL);
    net.setSerializer(std::make_unique<JsonSerializer>());
    ApiManager apiManager(net);
    // apiManager.loginUser("admin2", "admin2");
    // qDebug() << "sleeping";
    // apiManager.registerUser("admin4", "admin4");
    // qDebug() << "Sdldjsgldfghs";
    // apiManager.loginUser("admin4", "admin4");
    qDebug() << "attempt no 2";
    apiManager.addNewCustomer("bro", "0973333");
    qDebug() << "attempt no 3";
    apiManager.registerUser("dada", "dawda");

    // Client setup
    UiManager uiManager(app);
    LegalEdgeClient client(uiManager, apiManager);

    client.start();

    return app.exec();
}