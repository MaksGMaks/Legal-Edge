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

    QList<QString> list = {"C:\\sysprog\\test.txt", "C:\\sysprog\\test2.txt"};
    apiManager.createCase("newCase", list);

    QFile styleFile("C:\\LegalEdge\\_client\\style\\style.css");
    if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString styleSheet = QLatin1String(styleFile.readAll());

        app.setStyleSheet(styleSheet);
    }
    else
    {
        qDebug() << "Помилка: Неможливо завантажити CSS файл.";
    }
    // Client setup
    UiManager uiManager(app); //, apiManager
    LegalEdgeClient client(uiManager, apiManager);

    client.start();

    return app.exec();
}