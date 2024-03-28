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
    QCoreApplication a(argc, argv);
    NetworkService network(nullptr);
    network.setApiUrl(SERVER_API_URL);
    network.setSerializer(std::make_unique<JsonSerializer>());
    ApiManager api(network);
    api.loginUser("admin2", "admin2");
    return a.exec();


    // Client setup
    QApplication app(argc, argv);

    UiManager uiManager(app);
    LegalEdgeClient client(uiManager);

    client.start();

    return app.exec();
}