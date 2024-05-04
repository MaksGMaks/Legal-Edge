#include "LegalEdgeClient.hpp"

#include <QDebug>

#include "FilesReader/Reader.hpp"
#include "Ui/UiManager.hpp"
#include "network/ApiManager.hpp"

LegalEdgeClient::LegalEdgeClient(UiManager &uiManager, ApiManager &apiManager)
    : m_uiManager(uiManager),
      m_apiManager(apiManager)
{
    read = new Reader();
}

LegalEdgeClient::~LegalEdgeClient()
{
}

void LegalEdgeClient::start()
{
    qDebug() << "LegalEdgeClient: UiManager start UI";
    m_uiManager.startUi();

    m_apiManager.loginUser("admin2", "admin2");
}