#include <iostream>
#include <QApplication>

#include <QCoreApplication>

#include "network/ApiManager.hpp"
#include "network/JsonSerializer.hpp"

#include "LegalEdgeClient.hpp"
#include "Ui/UiManager.hpp"

const QString SERVER_API_URL{"http://127.0.0.1:8080/api"};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Network setup
    NetworkService network(nullptr);
    network.setApiUrl(SERVER_API_URL);
    network.setSerializer(std::make_unique<JsonSerializer>());
    ApiManager apiManager(network);
    
    // Client setup
    UiManager uiManager(app);
    LegalEdgeClient client(uiManager, apiManager);

    client.start();
    return app.exec();
}