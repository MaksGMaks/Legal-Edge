#pragma once

#include <QMainWindow>
#include <QTabWidget>
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

    void init(const QVector<QWidget *> widgets, const QVector<QString> names);

    // override resizeEvent
    void resizeEvent(QResizeEvent *event) override;

private:
    // tab widget
    QTabWidget *m_tabWidget;
};
