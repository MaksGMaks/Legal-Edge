#include "UiManager.hpp"

UiManager::UiManager(QApplication &app) noexcept
    : m_app(app)
{
    qDebug() << "UiManager: constructor";
    this->setupUi();
}

void UiManager::setupUi()
{
    qDebug() << "UiManager: constructor";
    m_mainWindow = new MainWindow();
}

void UiManager::startUi()
{
    qDebug() << "UiManager: MainWindow show maximized";
    m_mainWindow->show();
}

UiManager::~UiManager()
{
}