#pragma once

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>


class BooksOfLaws : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_exitLayout;
    QHBoxLayout *m_allButtonsLayout;
    QVBoxLayout *m_buttonsLayout1;
    QVBoxLayout *m_buttonsLayout2;
    QVBoxLayout *m_buttonsLayout3;
    QVBoxLayout *m_buttonsLayout4;

    QPushButton *m_administrativeJudiciaryCodex;
    QPushButton *m_administrativeOffensesCodex;
    QPushButton *m_airCodex;
    QPushButton *m_budgetCodex;
    QPushButton *m_civilCodex;
    QPushButton *m_civilProcedureCodex;
    QPushButton *m_civilProtecrionCodex;
    QPushButton *m_criminalAndExecutiveCodex;
    QPushButton *m_criminalCodex;
    QPushButton *m_criminalProcedureCodex;
    QPushButton *m_customsCodex;
    QPushButton *m_economicCodex;
    QPushButton *m_economicProcedualCodex;
    QPushButton *m_electionCodex;
    QPushButton *m_familyCodex;
    QPushButton *m_forestCodex;
    QPushButton *m_housingCodex;
    QPushButton *m_labourCodex;
    QPushButton *m_landCodex;
    QPushButton *m_merchantMaritimeCodex;
    QPushButton *m_proceduresBankruptcyCodex;
    QPushButton *m_subsoilCodex;
    QPushButton *m_taxCodex;
    QPushButton *m_waterCodex;

    QSpacerItem *m_rightExit;
    QSpacerItem *m_leftExit;
    QPushButton *m_exitButton;
    
    void connectButtons();

public:
    BooksOfLaws(QWidget *parent = nullptr);
    ~BooksOfLaws();

    void init();

signals:
    void openAdministrativeJudiciaryCodex();
    void openAdministrativeOffensesCodex();
    void openAirCodex();
    void openBudgetCodex();
    void openCivilCodex();
    void openCivilProcedureCodex();
    void openCivilProtectionCodex();
    void openCriminalAndExecutiveCodex();
    void openCriminalCodex();
    void openCriminalProcedureCodex();
    void openCustomsCodex();
    void openEconomicCodex();
    void openEconomicProcedualCodex();
    void openElectionCodex();
    void openFamilyCodex();
    void openForestCodex();
    void openHousingCodex();
    void openLabourCodex();
    void openLandCodex();
    void openMerchantMaritimeCodex();
    void openProceduresBankruptcyCodex();
    void openSubsoilCodex();
    void openTaxCodex();
    void openWaterCodex();
    void emitExit();

protected slots:
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
    void onExitButtonClicked();
};
