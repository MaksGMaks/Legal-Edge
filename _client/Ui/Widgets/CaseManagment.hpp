#pragma once

#include <QWidget>
#include <QPushButton>

class CaseManagment : public QWidget
{
    Q_OBJECT
private:
    QPushButton *m_createCase;
    QPushButton *m_myCases;
    QPushButton *m_manageDocs;
    QPushButton *m_addConsultation;
    QPushButton *m_contacts;

public:
    CaseManagment(QWidget *parent = nullptr);
    ~CaseManagment();

    void init();
};
