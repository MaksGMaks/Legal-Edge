#pragma once

#include <QWidget>
#include <QPushButton>

class Helper : public QWidget
{
    Q_OBJECT

private:
    QPushButton *m_bookOfLaws;
    QPushButton *m_notations;

public:
    Helper(QWidget *parent = nullptr);
    ~Helper();

    void init();
};
