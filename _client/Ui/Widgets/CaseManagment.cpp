#include "CaseManagment.hpp"

CaseManagment::CaseManagment(QWidget *parent) : QWidget(parent)
{
}

CaseManagment::~CaseManagment()
{
}

void CaseManagment::init()
{
    // init buttons
    // m_addConsultation = new QPushButton(tr("Add Consultation"));
    // m_addConsultation->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    // m_addConsultation->resize(Button::WIDTH, Button::HEIGHT);

    // m_contacts = new QPushButton(tr("Contacts"));
    // m_contacts->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    // m_contacts->resize(Button::WIDTH, Button::HEIGHT);

    m_createCase = new QPushButton(tr("Create Case"));
    m_createCase->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_createCase->resize(Button::WIDTH, Button::HEIGHT);

    m_myCases = new QPushButton(tr("My Cases"));
    m_myCases->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_myCases->resize(Button::WIDTH, Button::HEIGHT);

    // init spacers
    m_upButtonV = new QSpacerItem(20, 140, QSizePolicy::Minimum, QSizePolicy::Maximum);
    m_downButtonV = new QSpacerItem(20, 140, QSizePolicy::Minimum, QSizePolicy::Maximum);

    m_leftButtonH = new QSpacerItem(700, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    m_rightButtonH = new QSpacerItem(100, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

    // init layouts
    m_buttonStack = new QVBoxLayout();
    m_mainLayout = new QHBoxLayout(this);

    // fill button stack
    m_buttonStack->addSpacerItem(m_upButtonV);
    m_buttonStack->addWidget(m_createCase);
    m_buttonStack->addWidget(m_myCases);
    // m_buttonStack->addWidget(m_addConsultation);
    // m_buttonStack->addWidget(m_contacts);
    m_buttonStack->addSpacerItem(m_downButtonV);

    // fill main layout
    m_mainLayout->addSpacerItem(m_leftButtonH);
    m_mainLayout->addLayout(m_buttonStack);
    m_mainLayout->addSpacerItem(m_rightButtonH);
    this->setLayout(m_mainLayout);
}

void CaseManagment::connectButtons()
{
    // connect(m_addConsultation, &QPushButton::clicked, this, &CaseManagment::onAddConsultClicked);
    // connect(m_contacts, &QPushButton::clicked, this, &CaseManagment::onContactsClicked);
    connect(m_createCase, &QPushButton::clicked, this, &CaseManagment::onCreateCaseClicked);
    connect(m_myCases, &QPushButton::clicked, this, &CaseManagment::onMyCasesClicked);
}

void CaseManagment::onCreateCaseClicked()
{
    qDebug() << "LOG: CaseManagment::onCreateCaseClicked";
    emit createCase();
}

void CaseManagment::onMyCasesClicked()
{
    qDebug() << "LOG: CaseManagment::onMyCasesClicked";
    emit openMyCases();
}

// void CaseManagment::onAddConsultClicked()
// {
//     qDebug() << "LOG: CaseManagment::onAddConsultClicked";
//     emit addConsultation();
// }

// void CaseManagment::onContactsClicked()
// {
//     qDebug() << "LOG: CaseManagment::onContactsClicked";
//     emit openContacts();
// }