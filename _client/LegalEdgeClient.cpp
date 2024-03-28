#include "LegalEdgeClient.hpp"

#include <QDebug>

#include "Ui/UiManager.hpp"

LegalEdgeClient::LegalEdgeClient(UiManager &uiManager)
    : m_uiManager(uiManager)
{
}

LegalEdgeClient::~LegalEdgeClient()
{
}

void LegalEdgeClient::start()
{
    qDebug() << "LegalEdgeClient: UiManager start UI";
    m_uiManager.startUi();
}