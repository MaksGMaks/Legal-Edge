#include "Plans.hpp"

Plans::Plans(QWidget *parent) : QWidget(parent)
{
}

Plans::~Plans()
{
}

void Plans::init()
{
    // init buttons
    m_viewEvents = new QPushButton(tr("View Current Events"));
    m_viewEvents->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_viewEvents->resize(Button::WIDTH, Button::HEIGHT);

    m_addEvent = new QPushButton(tr("Add Event"));
    m_addEvent->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_addEvent->resize(Button::WIDTH, Button::HEIGHT);

    m_editData = new QPushButton(tr("Edit Data"));
    m_editData->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_editData->resize(Button::WIDTH, Button::HEIGHT);

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
    m_buttonStack->addWidget(m_viewEvents);
    m_buttonStack->addWidget(m_addEvent);
    m_buttonStack->addWidget(m_editData);
    m_buttonStack->addSpacerItem(m_downButtonV);

    // fill main layout
    m_mainLayout->addSpacerItem(m_leftButtonH);
    m_mainLayout->addLayout(m_buttonStack);
    m_mainLayout->addSpacerItem(m_rightButtonH);
    this->setLayout(m_mainLayout);
}

void Plans::connectButtons()
{
    connect(m_viewEvents, &QPushButton::clicked, this, &Plans::onViewEventsClicked);
    connect(m_addEvent, &QPushButton::clicked, this, &Plans::onAddEventClicked);
    connect(m_editData, &QPushButton::clicked, this, &Plans::onEditDataClicked);
}

void Plans::onViewEventsClicked()
{
    qDebug() << "LOG:Plans::onViewEventsClicked";
    emit openViewEvents();
}

void Plans::onAddEventClicked()
{
    qDebug() << "LOG:Plans::onAddEventClicked";
    emit openAddEvent();
}

void Plans::onEditDataClicked()
{
    qDebug() << "LOG:Plans::onEditDataClicked";
    emit openEditData();
}