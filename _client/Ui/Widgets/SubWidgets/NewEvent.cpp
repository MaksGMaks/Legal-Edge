#include "NewEvent.hpp"

NewEvent::NewEvent(QWidget *parent) : QWidget(parent)
{
}

NewEvent::~NewEvent()
{
}

void NewEvent::init()
{
    // init buttons
    m_work = new QPushButton(tr("Work"));
    m_work->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_work->resize(Button::WIDTH, Button::HEIGHT);

    m_personal = new QPushButton(tr("Personal"));
    m_personal->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_personal->resize(Button::WIDTH, Button::HEIGHT);

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
    m_buttonStack->addWidget(m_work);
    m_buttonStack->addWidget(m_personal);
    m_buttonStack->addWidget(m_exitButton);
    m_buttonStack->addSpacerItem(m_downButtonV);

    // fill main layout
    m_mainLayout->addSpacerItem(m_leftButtonH);
    m_mainLayout->addLayout(m_buttonStack);
    m_mainLayout->addSpacerItem(m_rightButtonH);
    this->setLayout(m_mainLayout);
}

void NewEvent::connectButtons()
{
    connect(m_work, &QPushButton::clicked, this, &NewEvent::onWorkClicked);
    connect(m_personal, &QPushButton::clicked, this, &NewEvent::onPersonalClicked);
    connect(m_exitButton, &QPushButton::clicked, this, &NewEvent::onExitClicked);
}

void NewEvent::onWorkClicked()
{
    qDebug() << "LOG: NewEvent::onWorkClicked";
    emit createWork();
}

void NewEvent::onPersonalClicked()
{
    qDebug() << "LOG: NewEvent::onPersonalClicked";
    emit createPersonal();
}

void NewEvent::onExitClicked()
{
    qDebug() << "LOG: NewEvent::onExitClicked";
    emit useExit();
}
