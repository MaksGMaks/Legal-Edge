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
    m_caseManagment = new CaseManagment();
    m_caseManagment->init();
    m_caseManagment->connectButtons();
    m_widgets.append(m_caseManagment);

    m_helper = new Helper();
    m_helper->init();
    m_helper->connectButtons();
    m_widgets.append(m_helper);

    m_mainWindow = new MainWindow();
    m_mainWindow->init(m_widgets);
}

void UiManager::startUi()
{
    qDebug() << "UiManager: MainWindow show maximized";
    m_mainWindow->show();
}

UiManager::~UiManager()
{
}