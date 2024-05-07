#pragma once

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

#include <QDebug>

#include "SubWidgets/Style.hpp"

class CaseManagment : public QWidget
{
    Q_OBJECT
private:
    // buttons
    QPushButton *m_createCase;
    QPushButton *m_myCases;
    // QPushButton *m_addConsultation;
    // QPushButton *m_contacts;

    // layouts
    QVBoxLayout *m_buttonStack;
    QHBoxLayout *m_mainLayout;

    // vertical spacers
    QSpacerItem *m_upButtonV;
    QSpacerItem *m_downButtonV;

    // horizontal spacers
    QSpacerItem *m_leftButtonH;
    QSpacerItem *m_rightButtonH;

public:
    CaseManagment(QWidget *parent = nullptr);
    ~CaseManagment();

    void init();
    void connectButtons();

signals:
    void createCase();
    void openMyCases();
    // void addConsultation();
    // void openContacts();

protected slots:
    void onCreateCaseClicked();
    void onMyCasesClicked();
    // void onAddConsultClicked();
    // void onContactsClicked();
};
