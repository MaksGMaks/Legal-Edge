#include "Helper.hpp"

Helper::Helper(QWidget *parent = nullptr) : QWidget(parent)
{
}

Helper::~Helper()
{
}

void Helper::init()
{
    m_notations = new QPushButton(tr("Notations"));
    m_bookOfLaws = new QPushButton(tr("Book of laws"));
}
