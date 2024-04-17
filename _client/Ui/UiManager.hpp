#pragma once

#include <QObject>
#include <QApplication>
#include <QVector>

#include "MainWindow.hpp"
#include "Widgets/CaseManagment.hpp"
#include "Widgets/Helper.hpp"

class UiManager : public QObject
{
    Q_OBJECT

public:
    explicit UiManager(QApplication &app) noexcept;
    virtual ~UiManager();

    void setupUi();
    void startUi();

protected:
    QApplication &m_app;
    MainWindow *m_mainWindow;

    QVector<QWidget *> m_widgets;
    CaseManagment *m_caseManagment;
    Helper *m_helper;
};