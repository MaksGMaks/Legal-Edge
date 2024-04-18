#pragma once

#include <QObject>
#include <QApplication>
#include <QVector>
#include <QStackedWidget>

#include "MainWindow.hpp"
#include "Widgets/CaseManagment.hpp"
#include "Widgets/Helper.hpp"
#include "Widgets/Plans.hpp"
#include "Widgets/SubWidgets/AddEvent.hpp"
#include "Widgets/SubWidgets/MyCases.hpp"
#include "Widgets/SubWidgets/NewEvent.hpp"

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
    QStackedWidget *m_plansWidgets;

    // vectors
    QVector<QWidget *> m_widgets;
    QVector<QString> m_widgetNames;

    // widgets
    CaseManagment *m_caseManagment;
    Helper *m_helper;
    Plans *m_plans;
    AddEvent *m_m_addEvent;
    MyCases *m_m_myCases;
    NewEvent *m_m_newEvent;

protected slots:
    // Case Managment main
    // void onCreateCaseClicked();
    void onMyCasesClicked(); //
    // void onManageDocsClicked();
    // void onAddConsultClicked();
    // void onContactsClicked();

    // Case Managment MyCases
    // void onActualCasesClicked();
    // void onSavedCasesClicked();
    // void onSavedDocsClicked();
    void onMainCasesExitClicked();

    // Plans main
    // void onViewEventsClicked();
    void onAddEventClicked(); //
    // void onEditDataClicked();

    // Plans AddEvent
    void onNewEventClicked(); //
    // void onPatternEventClicked();
    void onMainPlansExitClicked();

    // Plans NewEvent
    // void onWorkClicked();
    // void onPersonalClicked();
    void onPlansAddEventExitClicked();

    // Helper
    // void onBookOfLawsClicked();
    // void onNotationsClicked();
};