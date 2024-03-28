#pragma once

#include <QObject>
#include <QApplication>

#include "MainWindow.hpp"

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
};