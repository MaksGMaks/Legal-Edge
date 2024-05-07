#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QLabel>
#include <QList>

#include <QPdfLink>
#include <QPdfView>
#include <QPdfDocument>
#include <QPdfSearchModel>
#include <QPdfPageNavigator>

#include <QDebug>

#include "Style.hpp"

class SearchFieldComp : public QWidget
{
private:
    QPdfSearchModel *m_searchModel;
    QPdfView *m_view;
    QPdfPageNavigator *m_navigator;

    QPushButton *m_search;
    QPushButton *m_clear;
    QPushButton *m_nextResult;
    QPushButton *m_previousResult;

    QLineEdit *m_inputField;
    QLabel *m_currentResult;
    QLabel *m_allResults;
    QLabel *m_searchMessage1;
    QLabel *m_searchMessage2;
    QLabel *m_searchMessage3;

    QSpacerItem *m_messageCorection;

    QHBoxLayout *m_inputLine;
    QHBoxLayout *m_outputLine;
    QVBoxLayout *m_mainLayout;

    QList<QPdfLink> m_allResultsList;
    int currentItem = 1;

    void makeConections();

public slots:
    void onSearchClicked();
    void onClearClicked();
    void onPreviousResClicked();
    void onNextResClicked();
    

public:
    SearchFieldComp(QWidget *parent = nullptr);
    ~SearchFieldComp();

    void init(QPdfView *view);

};