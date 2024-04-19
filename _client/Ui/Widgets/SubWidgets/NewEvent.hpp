#pragma once

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

#include <QDebug>

#include "Style.hpp"

class NewEvent : public QWidget
{
    Q_OBJECT

private:
    // buttons
    QPushButton *m_work;
    QPushButton *m_personal;
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
    NewEvent(QWidget *parent = nullptr);
    ~NewEvent();

    void init();
    void connectButtons();

signals:
    void createWork();
    void createPersonal();
    void useExit();

protected slots:
    void onWorkClicked();
    void onPersonalClicked();
    void onExitClicked();
};