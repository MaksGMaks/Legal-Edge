#include "SearchFieldComp.hpp"

SearchFieldComp::SearchFieldComp(QWidget *parent) : QWidget(parent)
{
    
}

SearchFieldComp::~SearchFieldComp()
{

}

void SearchFieldComp::init(QPdfView *view)
{
    m_allResultsList.reserve(100);

    m_searchModel = new QPdfSearchModel();
    m_view = view;

    m_navigator = m_view->pageNavigator();

    m_search = new QPushButton(tr("Search"));
    
    m_clear = new QPushButton("X");
    m_clear->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_clear->setMaximumSize(25, 25);
    m_clear->resize(25, 25);

    m_previousResult = new QPushButton("<");
    m_previousResult->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_previousResult->setMaximumSize(25, 25);
    m_previousResult->resize(25, 25);

    m_nextResult = new QPushButton(">");
    m_nextResult->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_nextResult->setMaximumSize(25, 25);
    m_nextResult->resize(25, 25);

    m_inputField = new QLineEdit();
    m_currentResult = new QLabel("");
    m_allResults = new QLabel("");
    m_searchMessage1 = new QLabel(tr("Result  "));
    m_searchMessage2 = new QLabel(tr("  from  "));
    m_searchMessage3 = new QLabel(tr("  founded"));
    
    m_messageCorection = new QSpacerItem(700, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    m_inputLine = new QHBoxLayout();
    m_outputLine = new QHBoxLayout();
    m_mainLayout = new QVBoxLayout();

    m_inputLine->addWidget(m_inputField);
    m_inputLine->addWidget(m_previousResult);
    m_inputLine->addWidget(m_nextResult);
    m_inputLine->addWidget(m_clear);
    m_inputLine->addWidget(m_search);

    m_outputLine->addWidget(m_searchMessage1);
    m_outputLine->addWidget(m_currentResult);
    m_outputLine->addWidget(m_searchMessage2);
    m_outputLine->addWidget(m_allResults);
    m_outputLine->addWidget(m_searchMessage3);
    m_outputLine->addItem(m_messageCorection);
    
    m_mainLayout->addLayout(m_outputLine);
    m_mainLayout->addLayout(m_inputLine);

    m_inputField->setText("");
    m_searchMessage1->setVisible(false);
    m_searchMessage2->setVisible(false);
    m_searchMessage3->setVisible(false);
    m_currentResult->setVisible(false);
    m_allResults->setVisible(false);
    m_currentResult->setText("");
    m_allResults->setText("");

    this->setLayout(m_mainLayout);
    m_view->setSearchModel(m_searchModel);

    makeConections();
}   

void SearchFieldComp::makeConections()
{
    connect(m_search, &QPushButton::clicked, this, &SearchFieldComp::onSearchClicked);
    connect(m_clear, &QPushButton::clicked, this, &SearchFieldComp::onClearClicked);
    connect(m_previousResult, &QPushButton::clicked, this, &SearchFieldComp::onPreviousResClicked);
    connect(m_nextResult, &QPushButton::clicked, this, &SearchFieldComp::onNextResClicked);
}


void SearchFieldComp::onSearchClicked()
{
    qDebug() << "LOG: SearchFieldComp::onSearchClicked";

    if(!m_inputField->text().isEmpty() && m_view->document()!= nullptr)
    {
        m_allResultsList.clear();
        currentItem = 1;
        m_view->setCurrentSearchResultIndex(-1);
        m_searchModel->setDocument(m_view->document());
        m_searchModel->setSearchString(m_inputField->text());
        m_allResultsList = m_searchModel->resultsOnPage(0);
        
        for(int i = 1; i < m_view->document()->pageCount(); i++)
        {
            m_allResultsList += m_searchModel->resultsOnPage(i);
        }

        for(auto elemtny : m_allResultsList)
            qDebug() << "LOG: SearchFieldComp::onSearchClicked -- element pos" << elemtny.location() << "\n";

        qDebug() << "LOG: SearchFieldComp::onSearchClicked -- all results size" << m_allResultsList.size();

        m_searchMessage1->setVisible(true);
        m_searchMessage2->setVisible(true);
        m_searchMessage3->setVisible(true);

        if(m_allResultsList.size() != 0)
        {
            m_currentResult->setText(QString::number(currentItem));
            m_allResults->setText(QString::number(m_allResultsList.size()));

            m_currentResult->setVisible(true);
            m_allResults->setVisible(true);

            m_navigator->update(m_allResultsList[currentItem-1].page(), m_allResultsList[currentItem-1].location(), m_view->zoomFactor());
            m_navigator->forward();
            m_view->setCurrentSearchResultIndex(currentItem - 1);
        }
        else
        {
            m_currentResult->setText("0");
            m_allResults->setText("0");

            m_currentResult->setVisible(true);
            m_allResults->setVisible(true);
        }
        
    }
    
    
}

void SearchFieldComp::onClearClicked()
{
    qDebug() << "LOG: SearchFieldComp::onClearClicked";
    m_allResultsList.clear();
    currentItem = 1;
    m_inputField->setText("");
    m_searchMessage1->setVisible(false);
    m_searchMessage2->setVisible(false);
    m_searchMessage3->setVisible(false);
    m_currentResult->setVisible(false);
    m_allResults->setVisible(false);
    m_currentResult->setText("");
    m_allResults->setText("");
    m_view->setCurrentSearchResultIndex(-1);
}

void SearchFieldComp::onPreviousResClicked()
{
    qDebug() << "LOG: SearchFieldComp::onPreviousResClicked";
    if(m_allResultsList.size() > 0)
    {
        if(currentItem > 1)
        currentItem--;
        else
            currentItem = m_allResultsList.size();
        
        m_currentResult->setText(QString::number(currentItem));
        
        m_navigator->update(m_allResultsList[currentItem-1].page(), m_allResultsList[currentItem-1].location(), m_view->zoomFactor());
        m_navigator->forward();
        m_view->setCurrentSearchResultIndex(currentItem - 1);
    }    
}   

void SearchFieldComp::onNextResClicked()
{
    qDebug() << "LOG: SearchFieldComp::onNextResClicked";
    if(m_allResultsList.size() > 0)
    {
        if(currentItem < m_allResultsList.size())
            currentItem++;
        else
            currentItem = 1;
        
        m_currentResult->setText(QString::number(currentItem));
        
        
        m_navigator->update(m_allResultsList[currentItem-1].page(), m_allResultsList[currentItem-1].location(), m_view->zoomFactor());
        m_navigator->forward();
        m_view->setCurrentSearchResultIndex(currentItem - 1);
    }
}