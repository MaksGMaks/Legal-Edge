#include "UiManager.hpp"

UiManager::UiManager(QApplication &app, ApiManager &api) noexcept //, ApiManager &api
    : m_app(app),
    m_api(api)
{
    qDebug() << "UiManager: constructor";
    initBooks();
    initWidgets();
    connectWidgets();
    setupUi();
}

void UiManager::initWidgets()
{
    qDebug() << "UiManager: init widgets";
    // Case Managment
    m_casesWidgets = new QStackedWidget();

    m_caseManagment = new CaseManagment();
    m_caseManagment->init();
    m_caseManagment->connectButtons();
    m_casesWidgets->addWidget(m_caseManagment);

    m_cm_myCases = new MyCases();
    m_cm_myCases->init();
    m_cm_myCases->connectButtons();
    m_casesWidgets->addWidget(m_cm_myCases);

    m_cm_actualCases = new ActualCases();
    m_cm_actualCases->init(true);
    m_casesWidgets->addWidget(m_cm_actualCases);

    m_cm_savedCases = new SavedCases();
    m_cm_savedCases->init(true);
    m_casesWidgets->addWidget(m_cm_savedCases);

    m_cm_manageCases = new ManageCases();
    m_cm_manageCases->init();
    m_casesWidgets->addWidget(m_cm_manageCases);

    m_cm_createCase = new CreateCase();
    m_cm_createCase->init();
    m_casesWidgets->addWidget(m_cm_createCase);

    // QList<QString> testNames = {"case1", "case2"};
    // QList<QString> testPathes = {"E:/tests/case1", "E:/tests/case2"};

    // m_cm_actualCases->getCases(testNames, testPathes);
    // m_cm_savedCases->getCases(testNames, testPathes);

    // Plans
    // m_plansWidgets = new QStackedWidget();

    // m_plans = new Plans();
    // m_plans->init();
    // m_plans->connectButtons();
    // m_plansWidgets->addWidget(m_plans);

    // m_m_addEvent = new AddEvent();
    // m_m_addEvent->init();
    // m_m_addEvent->connectButtons();
    // m_plansWidgets->addWidget(m_m_addEvent);

    // m_m_newEvent = new NewEvent();
    // m_m_newEvent->init();
    // m_m_newEvent->connectButtons();
    // m_plansWidgets->addWidget(m_m_newEvent);

    // Helper
    m_helperWidgets = new QStackedWidget();

    m_helper = new Helper();
    m_helper->init();
    m_helper->connectButtons();

    m_helper_booksOfLaws = new BooksOfLaws();
    m_helper_booksOfLaws->init();

    m_helper_pdfReader = new PdfReader();
    m_helper_pdfReader->init();

    m_helperWidgets->addWidget(m_helper);
    m_helperWidgets->addWidget(m_helper_booksOfLaws);
    m_helperWidgets->addWidget(m_helper_pdfReader);

}

void UiManager::initBooks()
{
    booksPath = QDir::currentPath() + "/books";

    m_administrativeJudiciaryCodexPdf = new QPdfDocument();
    m_administrativeJudiciaryCodexPdf->load(booksPath + "/administrativeJudiciaryCodex.pdf");

    m_administrativeOffensesCodexPdf = new QPdfDocument();
    m_administrativeOffensesCodexPdf->load(booksPath + "/administrativeOffensesCodex.pdf");

    m_airCodexPdf = new QPdfDocument();
    m_airCodexPdf->load(booksPath + "/airCodex.pdf");

    m_budgetCodexPdf = new QPdfDocument();
    m_budgetCodexPdf->load(booksPath + "/budgetCodex.pdf");

    m_civilCodexPdf = new QPdfDocument();
    m_civilCodexPdf->load(booksPath + "/civilCodex.pdf");

    m_civilProcedureCodexPdf = new QPdfDocument();
    m_civilProcedureCodexPdf->load(booksPath + "/civilProcedureCodex.pdf");

    m_civilProtectionCodexPdf = new QPdfDocument();
    m_civilProtectionCodexPdf->load(booksPath + "/civilProtectionCodex.pdf");

    m_criminalAndExecutiveCodexPdf = new QPdfDocument();
    m_criminalAndExecutiveCodexPdf->load(booksPath + "/criminalAndExecutiveCodex.pdf");

    m_criminalCodexPdf = new QPdfDocument();
    m_criminalCodexPdf->load(booksPath + "/criminalCodex.pdf");

    m_criminalProcedureCodexPdf = new QPdfDocument();
    m_criminalProcedureCodexPdf->load(booksPath + "/criminalProcedureCodex.pdf");

    m_customsCodexPdf = new QPdfDocument();
    m_customsCodexPdf->load(booksPath + "/customsCodex.pdf");

    m_economicCodexPdf = new QPdfDocument();
    m_economicCodexPdf->load(booksPath + "/economicCodex.pdf");

    m_economicProcedualCodexPdf = new QPdfDocument();
    m_economicProcedualCodexPdf->load(booksPath + "/economicProcedualCodex.pdf");

    m_electionCodexPdf = new QPdfDocument();
    m_electionCodexPdf->load(booksPath + "/electionCodex.pdf");

    m_familyCodexPdf = new QPdfDocument();
    m_familyCodexPdf->load(booksPath + "/familyCodex.pdf");

    m_forestCodexPdf = new QPdfDocument();
    m_forestCodexPdf->load(booksPath + "/forestCodex.pdf");

    m_housingCodexPdf = new QPdfDocument();
    m_housingCodexPdf->load(booksPath + "/housingCodex.pdf");

    m_labourCodexPdf = new QPdfDocument();
    m_labourCodexPdf->load(booksPath + "/labourCodex.pdf");

    m_landCodexPdf = new QPdfDocument();
    m_landCodexPdf->load(booksPath + "/landCodex.pdf");

    m_merchantMaritimeCodexPdf = new QPdfDocument();
    m_merchantMaritimeCodexPdf->load(booksPath + "/merchantMaritimeCodex.pdf");

    m_proceduresBankruptcyCodexPdf = new QPdfDocument();
    m_proceduresBankruptcyCodexPdf->load(booksPath + "/proceduresBankruptcyCodex.pdf");

    m_subsoilCodexPdf = new QPdfDocument();
    m_subsoilCodexPdf->load(booksPath + "/subsoilCodex.pdf");

    m_taxCodexPdf = new QPdfDocument();
    m_taxCodexPdf->load(booksPath + "/taxCodex.pdf");

    m_waterCodexPdf = new QPdfDocument();
    m_waterCodexPdf->load(booksPath + "/waterCodex.pdf");

}

void UiManager::connectWidgets()
{
    qDebug() << "LOG::UiManager::connectButtons -- connect CaseManagment buttons"; 
    connect(m_caseManagment, &CaseManagment::openMyCases, this, &UiManager::onMyCasesClicked);
    connect(m_caseManagment, &CaseManagment::createCase, this, &UiManager::onCreateCaseClicked);

    connect(m_cm_myCases, &MyCases::openActualCases, this, &UiManager::onActualCasesClicked);
    connect(m_cm_actualCases, &ActualCases::emitExit, this, &UiManager::onMyCasesExitClicked);

    connect(m_cm_myCases, &MyCases::openSavedCases, this, &UiManager::onSavedCasesClicked);
    connect(m_cm_savedCases, &SavedCases::emitExit, this, &UiManager::onMyCasesExitClicked);

    connect(m_cm_createCase, &CreateCase::saveCase, m_api, &ApiManager::createCase);
    // connect(m_plans, &Plans::openAddEvent, this, &UiManager::onAddEventClicked);
    // connect(m_m_addEvent, &AddEvent::createNewEvent, this, &UiManager::onNewEventClicked);
    connect(m_cm_myCases, &MyCases::useExit, this, &UiManager::onMainCasesExitClicked);
    connect(m_cm_createCase, &CreateCase::emitExit, this, &UiManager::onMainCasesExitClicked);

    connect(m_cm_myCases, &MyCases::manageCases, this, &UiManager::onManageCasesClicked);
    connect(m_cm_manageCases, &ManageCases::emitExit, this, &UiManager::onMyCasesExitClicked);
    // connect(m_m_newEvent, &NewEvent::useExit, this, &UiManager::onPlansAddEventExitClicked);
    // connect(m_m_addEvent, &AddEvent::useExit, this, &UiManager::onMainPlansExitClicked);

    

    qDebug() << "LOG::UiManager::connectButtons -- connect books buttons"; 
    connect(m_helper_booksOfLaws, &BooksOfLaws::openAdministrativeJudiciaryCodex, this, &UiManager::onAdministrativeJudiciaryCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openAdministrativeOffensesCodex, this, &UiManager::onAdministrativeOffensesCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openAirCodex, this, &UiManager::onAirCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openBudgetCodex, this, &UiManager::onBudgetCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openCivilCodex, this, &UiManager::onCivilCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openCivilProcedureCodex, this, &UiManager::onCivilProcedureCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openCivilProtectionCodex, this, &UiManager::onCivilProtectionCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openCriminalAndExecutiveCodex, this, &UiManager::onCriminalAndExecutiveCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openCriminalCodex, this, &UiManager::onCriminalCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openCriminalProcedureCodex, this, &UiManager::onCriminalProcedureCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openCustomsCodex, this, &UiManager::onCustomsCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openEconomicCodex, this, &UiManager::onEconomicCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openEconomicProcedualCodex, this, &UiManager::onEconomicProcedualCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openElectionCodex, this, &UiManager::onElectionCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openFamilyCodex, this, &UiManager::onFamilyCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openForestCodex, this, &UiManager::onForestCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openHousingCodex, this, &UiManager::onHousingCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openLabourCodex, this, &UiManager::onLabourCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openLandCodex, this, &UiManager::onLandCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openMerchantMaritimeCodex, this, &UiManager::onMerchantMaritimeCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openProceduresBankruptcyCodex, this, &UiManager::onProceduresBankruptcyCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openSubsoilCodex, this, &UiManager::onSubsoilCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openTaxCodex, this, &UiManager::onTaxCodexClicked);
    connect(m_helper_booksOfLaws, &BooksOfLaws::openWaterCodex, this, &UiManager::onWaterCodexClicked);
    
    qDebug() << "LOG::UiManager::connectButtons -- connect helper buttons"; 

    connect(m_helper_booksOfLaws, &BooksOfLaws::emitExit, this, &UiManager::onBookOfLawsExitClicked);
    connect(m_helper_pdfReader, &PdfReader::emitExit, this, &UiManager::onPdfReaderExitClicked);
    connect(m_helper, &Helper::openBookOfLaws, this, &UiManager::onBookOfLawsClicked);
}

void UiManager::connectApi()
{
}

void UiManager::setupUi()
{
    qDebug() << "UiManager: constructor";
    m_widgets.append(m_casesWidgets);
    m_widgetNames.append("Case Managment");

    // m_widgets.append(m_plansWidgets);
    // m_widgetNames.append("Plans");

    m_widgets.append(m_helperWidgets);
    m_widgetNames.append("Helper");

    // m_widgets.append(m_helper_pdfReader);
    // m_widgetNames.append("test Reader");

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
    m_casesWidgets->setCurrentWidget(m_cm_myCases);
}

// void UiManager::onAddEventClicked()
// {
//     m_plansWidgets->setCurrentWidget(m_m_addEvent);
// }

// void UiManager::onNewEventClicked()
// {
//     m_plansWidgets->setCurrentWidget(m_m_newEvent);
// }

// void UiManager::onPlansAddEventExitClicked()
// {
//     m_plansWidgets->setCurrentWidget(m_m_addEvent);
// }

// void UiManager::onMainPlansExitClicked()
// {
//     m_plansWidgets->setCurrentWidget(m_plans);
// }

void UiManager::onMainCasesExitClicked()
{
    m_casesWidgets->setCurrentWidget(m_caseManagment);
}

void UiManager::onBookOfLawsClicked()
{
    m_helperWidgets->setCurrentWidget(m_helper_booksOfLaws);
}

void UiManager::onAdministrativeJudiciaryCodexClicked()
{
    m_helper_pdfReader->openPdf(m_administrativeJudiciaryCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onAdministrativeOffensesCodexClicked()
{
    m_helper_pdfReader->openPdf(m_administrativeOffensesCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onAirCodexClicked()
{
    m_helper_pdfReader->openPdf(m_airCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onBudgetCodexClicked()
{
    m_helper_pdfReader->openPdf(m_budgetCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onCivilCodexClicked()
{
    m_helper_pdfReader->openPdf(m_civilCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onCivilProcedureCodexClicked()
{
    m_helper_pdfReader->openPdf(m_civilProcedureCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onCivilProtectionCodexClicked()
{
    m_helper_pdfReader->openPdf(m_civilProtectionCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onCriminalAndExecutiveCodexClicked()
{
    m_helper_pdfReader->openPdf(m_criminalAndExecutiveCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onCriminalCodexClicked()
{
    m_helper_pdfReader->openPdf(m_criminalCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onCriminalProcedureCodexClicked()
{
    m_helper_pdfReader->openPdf(m_criminalProcedureCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onCustomsCodexClicked()
{
    m_helper_pdfReader->openPdf(m_customsCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onEconomicCodexClicked()
{
    m_helper_pdfReader->openPdf(m_economicCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onEconomicProcedualCodexClicked()
{
    m_helper_pdfReader->openPdf(m_economicProcedualCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onElectionCodexClicked()
{
    m_helper_pdfReader->openPdf(m_electionCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onFamilyCodexClicked()
{   
    m_helper_pdfReader->openPdf(m_familyCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onForestCodexClicked()
{
    m_helper_pdfReader->openPdf(m_forestCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onHousingCodexClicked()
{
    m_helper_pdfReader->openPdf(m_housingCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onLabourCodexClicked()
{
    m_helper_pdfReader->openPdf(m_labourCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onLandCodexClicked()
{
    m_helper_pdfReader->openPdf(m_landCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onMerchantMaritimeCodexClicked()
{
    m_helper_pdfReader->openPdf(m_merchantMaritimeCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onProceduresBankruptcyCodexClicked()
{
    m_helper_pdfReader->openPdf(m_proceduresBankruptcyCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onSubsoilCodexClicked()
{
    m_helper_pdfReader->openPdf(m_subsoilCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onTaxCodexClicked()
{
    m_helper_pdfReader->openPdf(m_taxCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onWaterCodexClicked()
{
    m_helper_pdfReader->openPdf(m_waterCodexPdf);
    m_helperWidgets->setCurrentWidget(m_helper_pdfReader);
}

void UiManager::onBookOfLawsExitClicked()
{
    m_helperWidgets->setCurrentWidget(m_helper);
}

void UiManager::onPdfReaderExitClicked()
{
    m_helperWidgets->setCurrentWidget(m_helper_booksOfLaws);
}

void UiManager::onCreateCaseClicked()
{
    m_casesWidgets->setCurrentWidget(m_cm_createCase);
}

void UiManager::onMyCasesExitClicked()
{
    m_casesWidgets->setCurrentWidget(m_cm_myCases);
}

void UiManager::onActualCasesClicked()
{
    m_casesWidgets->setCurrentWidget(m_cm_actualCases);
}

void UiManager::onSavedCasesClicked()
{
    m_casesWidgets->setCurrentWidget(m_cm_savedCases);
}

void UiManager::onManageCasesClicked()
{
    m_casesWidgets->setCurrentWidget(m_cm_manageCases);
}

void UiManager::onSaveCaseClicked()
{

}
