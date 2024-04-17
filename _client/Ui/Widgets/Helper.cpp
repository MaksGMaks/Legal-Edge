#include "Helper.hpp"

Helper::Helper(QWidget *parent) : QWidget(parent)
{
}

Helper::~Helper()
{
}

void Helper::init()
{
    // init buttons
    m_notations = new QPushButton(tr("Notations"));
    m_notations->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_notations->resize(Button::WIDTH, Button::HEIGHT);
    m_bookOfLaws = new QPushButton(tr("Book of laws"));
    m_bookOfLaws->setMaximumSize(Button::WIDTH, Button::HEIGHT);
    m_bookOfLaws->resize(Button::WIDTH, Button::HEIGHT);

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
    m_buttonStack->addWidget(m_bookOfLaws);
    m_buttonStack->addWidget(m_notations);
    m_buttonStack->addSpacerItem(m_downButtonV);

    // fill main layout
    m_mainLayout->addSpacerItem(m_leftButtonH);
    m_mainLayout->addLayout(m_buttonStack);
    m_mainLayout->addSpacerItem(m_rightButtonH);
    this->setLayout(m_mainLayout);
}

void Helper::connectButtons()
{
    connect(m_bookOfLaws, &QPushButton::clicked, this, &Helper::onBookOfLawsClicked);
    connect(m_notations, &QPushButton::clicked, this, &Helper::onNotationsClicked);
}

void Helper::onBookOfLawsClicked()
{
    qDebug() << "LOG: Helper::onBookOfLawsClicked";
    emit openBookOfLaws();
}

void Helper::onNotationsClicked()
{
    qDebug() << "LOG: Helper::onNotationsClicked";
    emit openNotations();
}
