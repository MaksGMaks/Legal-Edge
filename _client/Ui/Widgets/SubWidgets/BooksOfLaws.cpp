#include "BooksOfLaws.hpp"

BooksOfLaws::BooksOfLaws(QWidget *parent) : QWidget(parent)
{
}

BooksOfLaws::~BooksOfLaws()
{
}

void BooksOfLaws::init()
{
    m_mainLayout = new QVBoxLayout(this);
    m_exitLayout = new QHBoxLayout();
    m_allButtonsLayout = new QHBoxLayout();
    m_buttonsLayout1 = new QVBoxLayout();
    m_buttonsLayout2 = new QVBoxLayout();
    m_buttonsLayout3 = new QVBoxLayout();
    m_buttonsLayout4 = new QVBoxLayout();

    m_administrativeJudiciaryCodex = new QPushButton("Administrative Judiciary Codex");
    m_administrativeJudiciaryCodex->setMaximumSize(200, 60);
    m_administrativeJudiciaryCodex->resize(200, 60);

    m_administrativeOffensesCodex = new QPushButton("Administrative Offenses Codex");
    m_administrativeOffensesCodex->setMaximumSize(200, 60);
    m_administrativeOffensesCodex->resize(200, 60);

    m_airCodex = new QPushButton("Air Codex");
    m_airCodex->setMaximumSize(200, 60);
    m_airCodex->resize(200, 60);

    m_budgetCodex = new QPushButton("Budget Codex");
    m_budgetCodex->setMaximumSize(200, 60);
    m_budgetCodex->resize(200, 60);

    m_civilCodex = new QPushButton("Civil Codex");
    m_civilCodex->setMaximumSize(200, 60);
    m_civilCodex->resize(200, 60);

    m_civilProcedureCodex = new QPushButton("Civil Procedure Codex");
    m_civilProcedureCodex->setMaximumSize(200, 60);
    m_civilProcedureCodex->resize(200, 60);

    m_civilProtecrionCodex = new QPushButton("Civil Protection Codex");
    m_civilProtecrionCodex->setMaximumSize(200, 60);
    m_civilProtecrionCodex->resize(200, 60);

    m_criminalAndExecutiveCodex = new QPushButton("Criminal and Executive Codex");
    m_criminalAndExecutiveCodex->setMaximumSize(200, 60);
    m_criminalAndExecutiveCodex->resize(200, 60);

    m_criminalCodex = new QPushButton("Criminal Codex");
    m_criminalCodex->setMaximumSize(200, 60);
    m_criminalCodex->resize(200, 60);

    m_criminalProcedureCodex = new QPushButton("Criminal Procedure Codex");
    m_criminalProcedureCodex->setMaximumSize(200, 60);
    m_criminalProcedureCodex->resize(200, 60);

    m_customsCodex = new QPushButton("Customs Codex");
    m_customsCodex->setMaximumSize(200, 60);
    m_customsCodex->resize(200, 60);

    m_economicCodex = new QPushButton("Economic Codex");
    m_economicCodex->setMaximumSize(200, 60);
    m_economicCodex->resize(200, 60);

    m_economicProcedualCodex = new QPushButton("Economic Procedual Codex");
    m_economicProcedualCodex->setMaximumSize(200, 60);
    m_economicProcedualCodex->resize(200, 60);

    m_electionCodex = new QPushButton("Election Codex");
    m_electionCodex->setMaximumSize(200, 60);
    m_electionCodex->resize(200, 60);

    m_familyCodex = new QPushButton("Family Codex");
    m_familyCodex->setMaximumSize(200, 60);
    m_familyCodex->resize(200, 60);

    m_forestCodex = new QPushButton("Forest Codex");
    m_forestCodex->setMaximumSize(200, 60);
    m_forestCodex->resize(200, 60);

    m_housingCodex = new QPushButton("Housing Codex");
    m_housingCodex->setMaximumSize(200, 60);
    m_housingCodex->resize(200, 60);

    m_labourCodex = new QPushButton("Labour Codex");
    m_labourCodex->setMaximumSize(200, 60);
    m_labourCodex->resize(200, 60);

    m_landCodex = new QPushButton("Land Codex");
    m_landCodex->setMaximumSize(200, 60);
    m_landCodex->resize(200, 60);

    m_merchantMaritimeCodex = new QPushButton("Merchant Maritime Codex");
    m_merchantMaritimeCodex->setMaximumSize(200, 60);
    m_merchantMaritimeCodex->resize(200, 60);

    m_proceduresBankruptcyCodex = new QPushButton("Procedures of Bankruptcy Codex");
    m_proceduresBankruptcyCodex->setMaximumSize(200, 60);
    m_proceduresBankruptcyCodex->resize(200, 60);

    m_subsoilCodex = new QPushButton("Codex About Subsoil");
    m_subsoilCodex->setMaximumSize(200, 60);
    m_subsoilCodex->resize(200, 60);

    m_taxCodex = new QPushButton("Tax Codex");
    m_taxCodex->setMaximumSize(200, 60);
    m_taxCodex->resize(200, 60);

    m_waterCodex = new QPushButton("Water Codex");
    m_waterCodex->setMaximumSize(200, 60);
    m_waterCodex->resize(200, 60);

    m_exitButton = new QPushButton("Exit");
    m_exitButton->setMaximumSize(400, 60);
    m_exitButton->resize(400, 60);

    m_leftExit = new QSpacerItem(400, 60, QSizePolicy::Preferred, QSizePolicy::Minimum);
    m_rightExit = new QSpacerItem(400, 60, QSizePolicy::Preferred, QSizePolicy::Minimum);

    m_buttonsLayout1->addWidget(m_administrativeJudiciaryCodex);
    m_buttonsLayout1->addWidget(m_administrativeOffensesCodex);
    m_buttonsLayout1->addWidget(m_airCodex);
    m_buttonsLayout1->addWidget(m_budgetCodex);
    m_buttonsLayout1->addWidget(m_civilCodex);
    m_buttonsLayout1->addWidget(m_civilProcedureCodex);

    m_buttonsLayout2->addWidget(m_civilProtecrionCodex);
    m_buttonsLayout2->addWidget(m_criminalAndExecutiveCodex);
    m_buttonsLayout2->addWidget(m_criminalCodex);
    m_buttonsLayout2->addWidget(m_criminalProcedureCodex);
    m_buttonsLayout2->addWidget(m_customsCodex);
    m_buttonsLayout2->addWidget(m_economicCodex);

    m_buttonsLayout3->addWidget(m_economicProcedualCodex);
    m_buttonsLayout3->addWidget(m_electionCodex);
    m_buttonsLayout3->addWidget(m_familyCodex);
    m_buttonsLayout3->addWidget(m_forestCodex);
    m_buttonsLayout3->addWidget(m_housingCodex);
    m_buttonsLayout3->addWidget(m_labourCodex);

    m_buttonsLayout4->addWidget(m_landCodex);
    m_buttonsLayout4->addWidget(m_merchantMaritimeCodex);
    m_buttonsLayout4->addWidget(m_proceduresBankruptcyCodex);
    m_buttonsLayout4->addWidget(m_subsoilCodex);
    m_buttonsLayout4->addWidget(m_taxCodex);
    m_buttonsLayout4->addWidget(m_waterCodex);

    m_allButtonsLayout->addLayout(m_buttonsLayout1);
    m_allButtonsLayout->addLayout(m_buttonsLayout2);
    m_allButtonsLayout->addLayout(m_buttonsLayout3);
    m_allButtonsLayout->addLayout(m_buttonsLayout4);

    m_exitLayout->addItem(m_leftExit);
    m_exitLayout->addWidget(m_exitButton);
    m_exitLayout->addItem(m_rightExit);

    m_mainLayout->addLayout(m_allButtonsLayout);
    m_mainLayout->addLayout(m_exitLayout);

    connectButtons();
    
}

void BooksOfLaws::connectButtons()
{
    connect(m_administrativeJudiciaryCodex, &QPushButton::clicked, this, &BooksOfLaws::onAdministrativeJudiciaryCodexClicked);
    connect(m_administrativeOffensesCodex, &QPushButton::clicked, this, &BooksOfLaws::onAdministrativeOffensesCodexClicked);
    connect(m_airCodex, &QPushButton::clicked, this, &BooksOfLaws::onAirCodexClicked);
    connect(m_budgetCodex, &QPushButton::clicked, this, &BooksOfLaws::onBudgetCodexClicked);
    connect(m_civilCodex, &QPushButton::clicked, this, &BooksOfLaws::onCivilCodexClicked);
    connect(m_civilProcedureCodex, &QPushButton::clicked, this, &BooksOfLaws::onCivilProcedureCodexClicked);
    connect(m_civilProtecrionCodex, &QPushButton::clicked, this, &BooksOfLaws::onCivilProtectionCodexClicked);
    connect(m_criminalAndExecutiveCodex, &QPushButton::clicked, this, &BooksOfLaws::onCriminalAndExecutiveCodexClicked);
    connect(m_criminalCodex, &QPushButton::clicked, this, &BooksOfLaws::onCriminalCodexClicked);
    connect(m_criminalProcedureCodex, &QPushButton::clicked, this, &BooksOfLaws::onCriminalProcedureCodexClicked);
    connect(m_customsCodex, &QPushButton::clicked, this, &BooksOfLaws::onCustomsCodexClicked);
    connect(m_economicCodex, &QPushButton::clicked, this, &BooksOfLaws::onEconomicCodexClicked);
    connect(m_economicProcedualCodex, &QPushButton::clicked, this, &BooksOfLaws::onEconomicProcedualCodexClicked);
    connect(m_electionCodex, &QPushButton::clicked, this, &BooksOfLaws::onElectionCodexClicked);
    connect(m_familyCodex, &QPushButton::clicked, this, &BooksOfLaws::onFamilyCodexClicked);
    connect(m_forestCodex, &QPushButton::clicked, this, &BooksOfLaws::onForestCodexClicked);
    connect(m_housingCodex, &QPushButton::clicked, this, &BooksOfLaws::onHousingCodexClicked);
    connect(m_labourCodex, &QPushButton::clicked, this, &BooksOfLaws::onLabourCodexClicked);
    connect(m_landCodex, &QPushButton::clicked, this, &BooksOfLaws::onLandCodexClicked);
    connect(m_merchantMaritimeCodex, &QPushButton::clicked, this, &BooksOfLaws::onMerchantMaritimeCodexClicked);
    connect(m_proceduresBankruptcyCodex, &QPushButton::clicked, this, &BooksOfLaws::onProceduresBankruptcyCodexClicked);
    connect(m_subsoilCodex, &QPushButton::clicked, this, &BooksOfLaws::onSubsoilCodexClicked);
    connect(m_taxCodex, &QPushButton::clicked, this, &BooksOfLaws::onTaxCodexClicked);
    connect(m_waterCodex, &QPushButton::clicked, this, &BooksOfLaws::onWaterCodexClicked);

    connect(m_exitButton, &QPushButton::clicked, this, &BooksOfLaws::onExitButtonClicked);
}

void BooksOfLaws::onAdministrativeJudiciaryCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onAdministrativeJudiciaryCodexClicked\n";
    emit openAdministrativeJudiciaryCodex();
}

void BooksOfLaws::onAdministrativeOffensesCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onAdministrativeOffensesCodexClicked\n";
    emit openAdministrativeOffensesCodex();
}

void BooksOfLaws::onAirCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onAirCodexClicked\n";
    emit openAirCodex();
}

void BooksOfLaws::onBudgetCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onBudgetCodexClicked\n";
    emit openBudgetCodex();
}

void BooksOfLaws::onCivilCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onCivilCodexClicked\n";
    emit openCivilCodex();
}

void BooksOfLaws::onCivilProcedureCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onCivilProcedureCodexClicked\n";
    emit openCivilProcedureCodex();
}

void BooksOfLaws::onCivilProtectionCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onCivilProtectionCodexClicked\n";
    emit openCivilProtectionCodex();
}

void BooksOfLaws::onCriminalAndExecutiveCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onCriminalAndExecutiveCodexClicked\n";
    emit openCriminalAndExecutiveCodex();
}

void BooksOfLaws::onCriminalCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onCriminalCodexClicked\n";
    emit openCriminalCodex();
}

void BooksOfLaws::onCriminalProcedureCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onCriminalProcedureCodexClicked\n";
    emit openCriminalProcedureCodex();
}

void BooksOfLaws::onCustomsCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onCustomsCodexClicked\n";
    emit openCustomsCodex();
}

void BooksOfLaws::onEconomicCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onEconomicCodexClicked\n";
    emit openEconomicCodex();
}

void BooksOfLaws::onEconomicProcedualCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onEconomicProcedualCodexClicked\n";
    emit openEconomicProcedualCodex();
}

void BooksOfLaws::onElectionCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onElectionCodexClicked\n";
    emit openElectionCodex();
}

void BooksOfLaws::onFamilyCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onFamilyCodexClicked\n";
    emit openFamilyCodex();
}

void BooksOfLaws::onForestCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onForestCodexClicked\n";
    emit openForestCodex();
}

void BooksOfLaws::onHousingCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onHousingCodexClicked\n";
    emit openHousingCodex();
}

void BooksOfLaws::onLabourCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onLabourCodexClicked\n";
    emit openLabourCodex();
}

void BooksOfLaws::onLandCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onLandCodexClicked\n";
    emit openLandCodex();
}

void BooksOfLaws::onMerchantMaritimeCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onMerchantMaritimeCodexClicked\n";
    emit openMerchantMaritimeCodex();
}

void BooksOfLaws::onProceduresBankruptcyCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onProceduresBankruptcyCodexClicked\n";
    emit openProceduresBankruptcyCodex();
}

void BooksOfLaws::onSubsoilCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onSubsoilCodexClicked\n";
    emit openSubsoilCodex();
}

void BooksOfLaws::onTaxCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onTaxCodexClicked\n";
    emit openTaxCodex();
}

void BooksOfLaws::onWaterCodexClicked()
{
    qDebug() << "LOG::BooksOfLaws::onWaterCodexClicked\n";
    emit openWaterCodex();
}

void BooksOfLaws::onExitButtonClicked()
{
    qDebug() << "LOG::BooksOfLaws::onExitButtonClicked\n";
    emit emitExit();
}