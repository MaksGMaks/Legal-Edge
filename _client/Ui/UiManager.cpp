#include "UiManager.hpp"

UiManager::UiManager(QApplication &app) noexcept
    : m_app(app)
{
    qDebug() << "UiManager: constructor";
    initWidgets();
    connectWidgets();
    setupUi();
}

void UiManager::initWidgets()
{
    // Case Managment
    m_casesWidgets = new QStackedWidget();

    m_caseManagment = new CaseManagment();
    m_caseManagment->init();
    m_caseManagment->connectButtons();
    m_casesWidgets->addWidget(m_caseManagment);

    m_m_myCases = new MyCases();
    m_m_myCases->init();
    m_m_myCases->connectButtons();
    m_casesWidgets->addWidget(m_m_myCases);

    // Plans
    m_plansWidgets = new QStackedWidget();

    m_plans = new Plans();
    m_plans->init();
    m_plans->connectButtons();
    m_plansWidgets->addWidget(m_plans);

    m_m_addEvent = new AddEvent();
    m_m_addEvent->init();
    m_m_addEvent->connectButtons();
    m_plansWidgets->addWidget(m_m_addEvent);

    m_m_newEvent = new NewEvent();
    m_m_newEvent->init();
    m_m_newEvent->connectButtons();
    m_plansWidgets->addWidget(m_m_newEvent);

    // Helper
    m_helper = new Helper();
    m_helper->init();
    m_helper->connectButtons();
}

void UiManager::connectWidgets()
{
    connect(m_caseManagment, &CaseManagment::openMyCases, this, &UiManager::onMyCasesClicked);
    connect(m_plans, &Plans::openAddEvent, this, &UiManager::onAddEventClicked);
    connect(m_m_addEvent, &AddEvent::createNewEvent, this, &UiManager::onNewEventClicked);
    connect(m_m_myCases, &MyCases::useExit, this, &UiManager::onMainCasesExitClicked);
    connect(m_m_newEvent, &NewEvent::useExit, this, &UiManager::onPlansAddEventExitClicked);
    connect(m_m_addEvent, &AddEvent::useExit, this, &UiManager::onMainPlansExitClicked);
}

void UiManager::connectApi()
{
}

void UiManager::setupUi()
{
    qDebug() << "UiManager: constructor";
    m_widgets.append(m_casesWidgets);
    m_widgetNames.append("Case Managment");

    m_widgets.append(m_plansWidgets);
    m_widgetNames.append("Plans");

    m_widgets.append(m_helper);
    m_widgetNames.append("Helper");

    m_mainWindow = new MainWindow();
    m_mainWindow->init(m_widgets, m_widgetNames);
}

void UiManager::startUi()
{
    qDebug() << "UiManager: MainWindow show maximized";
    m_mainWindow->show();
}

UiManager::~UiManager()
{
}

void UiManager::onMyCasesClicked()
{
    m_casesWidgets->setCurrentWidget(m_m_myCases);
}

void UiManager::onAddEventClicked()
{
    m_plansWidgets->setCurrentWidget(m_m_addEvent);
}

void UiManager::onNewEventClicked()
{
    m_plansWidgets->setCurrentWidget(m_m_newEvent);
}

void UiManager::onPlansAddEventExitClicked()
{
    m_plansWidgets->setCurrentWidget(m_m_addEvent);
}

void UiManager::onMainPlansExitClicked()
{
    m_plansWidgets->setCurrentWidget(m_plans);
}

void UiManager::onMainCasesExitClicked()
{
    m_casesWidgets->setCurrentWidget(m_caseManagment);
}