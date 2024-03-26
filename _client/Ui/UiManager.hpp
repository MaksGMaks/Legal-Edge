#pragma once

#include <QObject>
#include <QApplication>

class UiManager : public QObject
{
    Q_OBJECT

public:
    UiManager(QApplication &app);
    virtual ~UiManager();

protected:
    QApplication &m_app;
};