#include "CaseManagment.hpp"

CaseManagment::CaseManagment(QWidget *parent = nullptr) : QWidget(parent)
{
}

CaseManagment::~CaseManagment()
{
}

void CaseManagment::init()
{
    m_addConsultation = new QPushButton(tr("Add Consultation"));
    m_contacts = new QPushButton(tr("Contacts"));
    m_createCase = new QPushButton(tr("Create Case"));
    m_manageDocs = new QPushButton(tr("Manage Documents"));
    m_myCases = new QPushButton(tr("My Cases"));
}