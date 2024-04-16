#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <QMenuBar>
#include <QMenu>
#include <QString>
#include <QLabel>
#include <QHBoxLayout>
#include <QVector>

#include <QDebug>
#include <QStatusBar>

#include "Widgets/Style.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

    void init(const QVector<QWidget *> widgets);

    // override resizeEvent
    void resizeEvent(QResizeEvent *event) override;

private:
    // stack view
    QStackedWidget *m_stackView;

    // menu bar
    QMenuBar *m_mainMenuBar;

    // functions
    // void pageHandler(int index);
    // void createMenu(QMenuBar *menu, const QString &text, int index);
};
