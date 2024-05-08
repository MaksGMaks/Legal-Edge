#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include "InputAreaComp.hpp"


class CreateCase : public QWidget
{
    Q_OBJECT

private:
    QPushButton *m_save;
    QLineEdit *m_title;

    QLabel *m_nameLabel;
    QLabel *m_dowloadDocument;

    QVBoxLayout *m_itemsLayout;
    QHBoxLayout *m_mainLayout;

    InputAreaComp *m_inputArea;

    QSpacerItem *m_rightSpace;

    QPushButton *m_exitButton;

public:
    CreateCase(QWidget *parent = nullptr);
    ~CreateCase();
    
    void init();

signals:
    void saveCase();
    void emitExit();

protected slots:
    void onSaveClicked();
    void onExitButtonClicked();

};