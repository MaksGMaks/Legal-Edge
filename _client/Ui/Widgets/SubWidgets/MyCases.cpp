#include "MyCases.hpp"

MyCases::MyCases(QWidget *parent) : QWidget(parent)
{
}

MyCases::~MyCases()
{
}

void MyCases::init()
{
    // init buttons
    m_actualCases = new QPushButton(tr("Actual Cases"));
    m_actualCases->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_actualCases->resize(Button::WIDTH, Button::HEIGHT);

    m_savedCases = new QPushButton(tr("Saved Cases"));
    m_savedCases->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_savedCases->resize(Button::WIDTH, Button::HEIGHT);

    m_manageCases = new QPushButton(tr("Manage Documents"));
    m_manageCases->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_manageCases->resize(Button::WIDTH, Button::HEIGHT);

    m_exitButton = new QPushButton(tr("Exit"));
    m_exitButton->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_exitButton->resize(Button::WIDTH, Button::HEIGHT);

    // init spacers
    m_upButtonV = new QSpacerItem(20, 180, QSizePolicy::Minimum, QSizePolicy::Maximum);
    m_downButtonV = new QSpacerItem(20, 180, QSizePolicy::Minimum, QSizePolicy::Maximum);

    m_leftButtonH = new QSpacerItem(700, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    m_rightButtonH = new QSpacerItem(100, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

    // init layouts
    m_buttonStack = new QVBoxLayout();
    m_mainLayout = new QHBoxLayout(this);

    // fill button stack
    m_buttonStack->addSpacerItem(m_upButtonV);
    m_buttonStack->addWidget(m_actualCases);
    m_buttonStack->addWidget(m_savedCases);
    m_buttonStack->addWidget(m_manageCases);
    m_buttonStack->addWidget(m_exitButton);
    m_buttonStack->addSpacerItem(m_downButtonV);

    // fill main layout
    m_mainLayout->addSpacerItem(m_leftButtonH);
    m_mainLayout->addLayout(m_buttonStack);
    m_mainLayout->addSpacerItem(m_rightButtonH);
    this->setLayout(m_mainLayout);
}

void MyCases::connectButtons()
{
    connect(m_actualCases, &QPushButton::clicked, this, &MyCases::onActualCasesClicked);
    connect(m_savedCases, &QPushButton::clicked, this, &MyCases::onSavedCasesClicked);
    connect(m_manageCases, &QPushButton::clicked, this, &MyCases::onManageCasesClicked);
    connect(m_exitButton, &QPushButton::clicked, this, &MyCases::onExitClicked);
}

void MyCases::onActualCasesClicked()
{
    qDebug() << "LOG:MyCases::onWorkClicked";
    emit openActualCases();
}

void MyCases::onSavedCasesClicked()
{
    qDebug() << "LOG:MyCases::onSavedCasesClicked";
    emit openSavedCases();
}

void MyCases::onManageCasesClicked()
{
    qDebug() << "LOG: MyCases::onManageCasesClicked";
    emit manageCases();
}

void MyCases::onExitClicked()
{
    qDebug() << "LOG: MyCases::onExitClicked";
    emit useExit();
}
