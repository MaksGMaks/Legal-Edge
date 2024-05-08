#pragma once

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QComboBox>

#include <QDebug>

#include "Style.hpp"

class Notation : public QWidget
{
    Q_OBJECT

private:

    QComboBox *m_cases;

    QPushButton *m_exitButton;

public:

    Notation(QWidget *parent = nullptr);
    ~Notation();

    void init();
    void getCases(const QList<QString> casesName, const QList<QString> casesPath);


};