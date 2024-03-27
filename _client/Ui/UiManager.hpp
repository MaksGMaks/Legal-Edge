#pragma once

#include <QObject>
#include <QApplication>

#include "MainWindow.hpp"

class UiManager : public QObject
{
    Q_OBJECT

public:
    UiManager(QApplication &app);
    virtual ~UiManager();

protected:
    QApplication &m_app;
    MainWindow *m_mainWindow;
};