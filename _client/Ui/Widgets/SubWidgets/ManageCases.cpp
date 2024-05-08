#include "ManageCases.hpp"

ManageCases::ManageCases(QWidget *parent) : QWidget(parent)
{

}

ManageCases::~ManageCases()
{

}

void ManageCases::init()
{
    m_cases = new QComboBox();
    m_saveCase = new QPushButton("Save Changes");
    m_makeActual = new QPushButton("Make Actual");
    m_makeSaved = new QPushButton("Make Saved");

    m_exitButton = new QPushButton("Exit");

    m_isActual = new QLabel("Is Actual");
    m_isSaved = new QLabel("Is Saved");

    m_actualSection = new QVBoxLayout();
    m_savedSection = new QVBoxLayout();

    m_mainLayout = new QVBoxLayout();
    m_caseManagment = new QHBoxLayout();

    m_rightSpaceIsSaved = new QSpacerItem(400, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    m_leftSpaceIsSaved = new QSpacerItem(400, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    
    m_rightSpaceIsActual = new QSpacerItem(400, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    m_leftSpaceIsActual = new QSpacerItem(400, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

    m_rightSpaceSaveCase = new QSpacerItem(400, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    m_leftSpaceSaveCase = new QSpacerItem(400, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

    m_rightSpaceExit = new QSpacerItem(400, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    m_leftSpaceExit = new QSpacerItem(400, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

    m_isSavedLayout = new QHBoxLayout();
    m_isSavedLayout->addSpacerItem(m_leftSpaceIsSaved);
    m_isSavedLayout->addWidget(m_isSaved);
    m_isSavedLayout->addSpacerItem(m_rightSpaceIsSaved);

    m_isActualLayout = new QHBoxLayout();
    m_isActualLayout->addSpacerItem(m_leftSpaceIsActual);
    m_isActualLayout->addWidget(m_isActual);
    m_isActualLayout->addSpacerItem(m_rightSpaceIsActual);

    m_saveCaseLayout = new QHBoxLayout();
    m_saveCaseLayout->addSpacerItem(m_leftSpaceSaveCase);
    m_saveCaseLayout->addWidget(m_saveCase);
    m_saveCaseLayout->addSpacerItem(m_rightSpaceSaveCase);

    m_exitLayout = new QHBoxLayout();
    m_exitLayout->addSpacerItem(m_leftSpaceExit);
    m_exitLayout->addWidget(m_exitButton);
    m_exitLayout->addSpacerItem(m_rightSpaceExit);

    m_actualSection->addLayout(m_isActualLayout);
    m_actualSection->addWidget(m_makeActual);

    m_savedSection->addLayout(m_isSavedLayout);
    m_savedSection->addWidget(m_makeSaved);

    m_caseManagment->addLayout(m_actualSection);
    m_caseManagment->addLayout(m_savedSection);

    m_upSpace = new QSpacerItem(30, 50, QSizePolicy::Minimum, QSizePolicy::Preferred);
    m_downSpace = new QSpacerItem(30, 50, QSizePolicy::Minimum, QSizePolicy::Preferred);

    m_mainLayout->addSpacerItem(m_upSpace);
    m_mainLayout->addWidget(m_cases);
    m_mainLayout->addLayout(m_caseManagment);
    m_mainLayout->addLayout(m_saveCaseLayout);
    m_mainLayout->addLayout(m_exitLayout);
    m_mainLayout->addSpacerItem(m_downSpace);

    setLayout(m_mainLayout);

    connect(m_exitButton, &QPushButton::clicked, this, &ManageCases::onExitButtonClicked);

}

void ManageCases::onExitButtonClicked()
{
    emit emitExit();
}

void ManageCases::reciveAllCases()
{

}