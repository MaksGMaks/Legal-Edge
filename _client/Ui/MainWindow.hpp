#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>

#include "Style.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

    void init();

    // override resizeEvent
    void resizeEvent(QResizeEvent *event) override;

private:
    // stack view
    QStackedWidget *m_stackView;

    // menu bar
    QMenuBar *m_mainMenuBar;
};
