#include <iostream>

#include <QCoreApplication>
#include <QApplication>
#include <QList>

#include "network/ApiManager.hpp"
#include "network/JsonSerializer.hpp"

#include "Ui/UiManager.hpp"
#include "LegalEdgeClient.hpp"

const QString SERVER_API_URL{"http://127.0.0.1:8080/api"};

int main(int argc, char *argv[])
{
    // Network setup
    QApplication app(argc, argv);
    NetworkService net(nullptr);
    net.setApiUrl(SERVER_API_URL);
    net.setSerializer(std::make_unique<JsonSerializer>());
    ApiManager apiManager(net);
    qDebug() << "notes attempt";
    apiManager.getAllNotes();

<<<<<<< HEAD
    QList<QString> list = {"C:\\sysprog\\test.txt", "C:\\sysprog\\test2.txt"};
    apiManager.createCase("newCase", list);

=======
    //apiManager.createCase("asasas");
>>>>>>> 9cc9c3eb649a8cd73c3d4274df52303888741906
    // Client setup
    UiManager uiManager(app); //, apiManager
    LegalEdgeClient client(uiManager, apiManager);

    client.start();

    return app.exec();
}