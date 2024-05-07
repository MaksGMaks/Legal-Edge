#pragma once

#include <QObject>
#include <QApplication>
#include <QVector>
#include <QStackedWidget>
#include <QPdfDocument>
#include <QDir>

#include "MainWindow.hpp"
#include "Widgets/CaseManagment.hpp"
#include "Widgets/Helper.hpp"
#include "Widgets/Plans.hpp"
// #include "Widgets/SubWidgets/AddEvent.hpp"
#include "Widgets/SubWidgets/MyCases.hpp"
// #include "Widgets/SubWidgets/NewEvent.hpp"
#include "Widgets/SubWidgets/BooksOfLaws.hpp"
#include "Widgets/SubWidgets/CreateCase.hpp"
#include "Widgets/SubWidgets/WatchCases.hpp"

#include "Widgets/SubWidgets/PdfReader.hpp"



class UiManager : public QObject
{
    Q_OBJECT

public:
    explicit UiManager(QApplication &app) noexcept;
    virtual ~UiManager();

    void initWidgets();
    void connectWidgets();
    void connectApi();
    void setupUi();
    void startUi();

protected:
    QApplication &m_app;
    MainWindow *m_mainWindow;

    // stack widgets
    QStackedWidget *m_casesWidgets;
    // QStackedWidget *m_plansWidgets;
    QStackedWidget *m_helperWidgets;

    // vectors
    QVector<QWidget *> m_widgets;
    QVector<QString> m_widgetNames;

    // widgets
    // CaseManagment
    CaseManagment *m_caseManagment;
    MyCases *m_cm_myCases;
    CreateCase *m_cm_createCase;
    WatchCases *m_cm_actualCases;
    WatchCases *m_cm_savedCases;
    

    // Plans
    // Plans *m_plans;
    // AddEvent *m_m_addEvent;
    // NewEvent *m_m_newEvent;
    
    // Helper
    Helper *m_helper;
    BooksOfLaws *m_helper_booksOfLaws;
    PdfReader *m_helper_pdfReader;

    // Books
    QString booksPath;
    QPdfDocument *m_administrativeJudiciaryCodexPdf;
    QPdfDocument *m_administrativeOffensesCodexPdf;
    QPdfDocument *m_airCodexPdf;
    QPdfDocument *m_budgetCodexPdf;
    QPdfDocument *m_civilCodexPdf;
    QPdfDocument *m_civilProcedureCodexPdf;
    QPdfDocument *m_civilProtectionCodexPdf;
    QPdfDocument *m_criminalAndExecutiveCodexPdf;
    QPdfDocument *m_criminalCodexPdf;
    QPdfDocument *m_criminalProcedureCodexPdf;
    QPdfDocument *m_customsCodexPdf;
    QPdfDocument *m_economicCodexPdf;
    QPdfDocument *m_economicProcedualCodexPdf;
    QPdfDocument *m_electionCodexPdf;
    QPdfDocument *m_familyCodexPdf;
    QPdfDocument *m_forestCodexPdf;
    QPdfDocument *m_housingCodexPdf;
    QPdfDocument *m_labourCodexPdf;
    QPdfDocument *m_landCodexPdf;
    QPdfDocument *m_merchantMaritimeCodexPdf;
    QPdfDocument *m_proceduresBankruptcyCodexPdf;
    QPdfDocument *m_subsoilCodexPdf;
    QPdfDocument *m_taxCodexPdf;
    QPdfDocument *m_waterCodexPdf;

    void initBooks();

protected slots:
    // Case Managment main
    void onCreateCaseClicked();
    void onMyCasesClicked(); 
    // void onManageCasesClicked();
    // void onAddConsultClicked();
    // void onContactsClicked();

    // Case Managment MyCases
    void onActualCasesClicked();
    void onSavedCasesClicked();
    void onMainCasesExitClicked();

    // Case Managment CreateCase
    void onMyCasesExitClicked();

    // Plans main
    // void onViewEventsClicked();
    // void onAddEventClicked(); 
    // void onEditDataClicked();

    // Plans AddEvent
    // void onNewEventClicked(); 
    // void onPatternEventClicked();
    // void onMainPlansExitClicked();

    // Plans NewEvent
    // void onWorkClicked();
    // void onPersonalClicked();
    // void onPlansAddEventExitClicked();

    // Helper
    void onBookOfLawsClicked();
    // void onNotationsClicked();
    
    void onBookOfLawsExitClicked();
    void onPdfReaderExitClicked();

    // Books hadler
    void onAdministrativeJudiciaryCodexClicked();
    void onAdministrativeOffensesCodexClicked();
    void onAirCodexClicked();
    void onBudgetCodexClicked();
    void onCivilCodexClicked();
    void onCivilProcedureCodexClicked();
    void onCivilProtectionCodexClicked();
    void onCriminalAndExecutiveCodexClicked();
    void onCriminalCodexClicked();
    void onCriminalProcedureCodexClicked();
    void onCustomsCodexClicked();
    void onEconomicCodexClicked();
    void onEconomicProcedualCodexClicked();
    void onElectionCodexClicked();
    void onFamilyCodexClicked();
    void onForestCodexClicked();
    void onHousingCodexClicked();
    void onLabourCodexClicked();
    void onLandCodexClicked();
    void onMerchantMaritimeCodexClicked();
    void onProceduresBankruptcyCodexClicked();
    void onSubsoilCodexClicked();
    void onTaxCodexClicked();
    void onWaterCodexClicked();
    

};