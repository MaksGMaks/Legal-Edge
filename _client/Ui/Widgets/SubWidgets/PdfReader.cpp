#include "PdfReader.hpp"

PdfReader::PdfReader(QWidget *parent) : QWidget(parent)
{

}

void PdfReader::openPdf(QPdfDocument *document)
{
    if (document != nullptr)
    {
        m_view->setDocument(document);
    }
}

PdfReader::~PdfReader()
{

}


void PdfReader::init()
{
    m_layout = new QVBoxLayout(this);
    m_view = new QPdfView(this);
    m_layout->addWidget(m_view);

    m_exitButton = new QPushButton("Exit");

    m_searchField = new SearchFieldComp();
    m_searchField->init(m_view);

    m_view->setPageMode(QPdfView::PageMode::MultiPage);

    m_layout->addWidget(m_searchField);
    m_layout->addWidget(m_exitButton);

    connect(m_exitButton, &QPushButton::clicked, this, &PdfReader::onExitButtonClicked);
}

void PdfReader::onExitButtonClicked()
{
    emit emitExit();
}