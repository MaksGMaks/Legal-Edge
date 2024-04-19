#pragma once

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

#include <QDebug>

#include "SubWidgets/Style.hpp"

class Plans : public QWidget
{
    Q_OBJECT

private:
    // buttons
    QPushButton *m_viewEvents;
    QPushButton *m_addEvent;
    QPushButton *m_editData;

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
    Plans(QWidget *parent = nullptr);
    ~Plans();

    void init();
    void connectButtons();

signals:
    void openViewEvents();
    void openAddEvent();
    void openEditData();

protected slots:
    void onViewEventsClicked();
    void onAddEventClicked();
    void onEditDataClicked();
};
