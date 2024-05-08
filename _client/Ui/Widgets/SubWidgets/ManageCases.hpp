#pragma once

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QVector>
#include <QList>
#include <QLabel>
#include <QSpacerItem>

class ManageCases : public QWidget
{
    Q_OBJECT

private:
    QComboBox *m_cases;
    QPushButton *m_saveCase;
    QPushButton *m_makeActual;
    QPushButton *m_makeSaved;
    QPushButton *m_exitButton;

    QLabel *m_isActual;
    QLabel *m_isSaved;

    QVBoxLayout *m_actualSection;
    QVBoxLayout *m_savedSection;

    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_caseManagment;

    QSpacerItem *m_rightSpaceIsSaved;
    QSpacerItem *m_leftSpaceIsSaved;
    
    QSpacerItem *m_rightSpaceIsActual;
    QSpacerItem *m_leftSpaceIsActual;

    QSpacerItem *m_rightSpaceSaveCase;
    QSpacerItem *m_leftSpaceSaveCase;

    QSpacerItem *m_rightSpaceExit;
    QSpacerItem *m_leftSpaceExit;

    QHBoxLayout *m_isSavedLayout;

    QHBoxLayout *m_isActualLayout;

    QHBoxLayout *m_saveCaseLayout;

    QHBoxLayout *m_exitLayout;

    QSpacerItem *m_upSpace;
    QSpacerItem *m_downSpace;

public:
    ManageCases(QWidget *parent = nullptr);
    ~ManageCases();

    void init();

protected slots:
    void reciveAllCases();
    void onExitButtonClicked();

signals:
    void askAllCases();
    void emitExit();
};