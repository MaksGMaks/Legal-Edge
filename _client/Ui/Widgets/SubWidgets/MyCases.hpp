#pragma once

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

#include <QDebug>

#include "Style.hpp"

class MyCases : public QWidget
{
    Q_OBJECT

private:
    // buttons
    QPushButton *m_actualCases;
    QPushButton *m_savedCases;
    QPushButton *m_savedDocs;
    QPushButton *m_exitButton;

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
    MyCases(QWidget *parent = nullptr);
    ~MyCases();

    void init();
    void connectButtons();

signals:
    void openActualCases();
    void openSavedCases();
    void openSavedDocs();
    void useExit();

protected slots:
    void onActualCasesClicked();
    void onSavedCasesClicked();
    void onSavedDocsClicked();
    void onExitClicked();
};