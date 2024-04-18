#pragma once

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

#include <QDebug>

#include "Style.hpp"

class AddEvent : public QWidget
{
    Q_OBJECT

private:
    // buttons
    QPushButton *m_bookOfLaws;
    QPushButton *m_notations;

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
    AddEvent(QWidget *parent = nullptr);
    ~AddEvent();

    void init();
    void connectButtons();

signals:
    void openBookOfLaws();
    void openNotations();

protected slots:
    void onBookOfLawsClicked();
    void onNotationsClicked();
};