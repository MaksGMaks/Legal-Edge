#include "AddEvent.hpp"

AddEvent::AddEvent(QWidget *parent) : QWidget(parent)
{
}

AddEvent::~AddEvent()
{
}

void AddEvent::init()
{
    // init buttons
    m_newEvent = new QPushButton(tr("New Event"));
    m_newEvent->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_newEvent->resize(Button::WIDTH, Button::HEIGHT);

    m_patternEvent = new QPushButton(tr("Pattern Event"));
    m_patternEvent->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_patternEvent->resize(Button::WIDTH, Button::HEIGHT);

    m_exitButton = new QPushButton(tr("Exit"));
    m_exitButton->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_exitButton->resize(Button::WIDTH, Button::HEIGHT);

    // init spacers
    m_upButtonV = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Maximum);
    m_downButtonV = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Maximum);

    m_leftButtonH = new QSpacerItem(700, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    m_rightButtonH = new QSpacerItem(100, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

    // init layouts
    m_buttonStack = new QVBoxLayout();
    m_mainLayout = new QHBoxLayout(this);

    // fill button stack
    m_buttonStack->addSpacerItem(m_upButtonV);
    m_buttonStack->addWidget(m_newEvent);
    m_buttonStack->addWidget(m_patternEvent);
    m_buttonStack->addWidget(m_exitButton);
    m_buttonStack->addSpacerItem(m_downButtonV);

    // fill main layout
    m_mainLayout->addSpacerItem(m_leftButtonH);
    m_mainLayout->addLayout(m_buttonStack);
    m_mainLayout->addSpacerItem(m_rightButtonH);
    this->setLayout(m_mainLayout);
}

void AddEvent::connectButtons()
{
    connect(m_newEvent, &QPushButton::clicked, this, &AddEvent::onNewEventClicked);
    connect(m_patternEvent, &QPushButton::clicked, this, &AddEvent::onPatternEventClicked);
    connect(m_exitButton, &QPushButton::clicked, this, &AddEvent::onExitClicked);
}

void AddEvent::onNewEventClicked()
{
    qDebug() << "LOG: AddEvent::onNewEventClicked";
    emit createNewEvent();
}

void AddEvent::onPatternEventClicked()
{
    qDebug() << "LOG: AddEvent::onPatternEventClicked";
    emit createPatternEvent();
}

void AddEvent::onExitClicked()
{
    qDebug() << "LOG: AddEvent::onExitClicked";
    emit useExit();
}
