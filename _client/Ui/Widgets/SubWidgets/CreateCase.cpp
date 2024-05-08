#include "CreateCase.hpp"

CreateCase::CreateCase(QWidget *parent) : QWidget(parent)
{
}

CreateCase::~CreateCase()
{
}

void CreateCase::init()
{
    m_save = new QPushButton("Save");
    m_title = new QLineEdit();
    m_nameLabel = new QLabel("Name of the case");
    m_dowloadDocument = new QLabel("Put documents here/Double click to delete");
    m_inputArea = new InputAreaComp();
    m_exitButton = new QPushButton("Exit");

    m_rightSpace = new QSpacerItem(400, 100, QSizePolicy::Preferred, QSizePolicy::Minimum);

    m_itemsLayout = new QVBoxLayout();
    m_itemsLayout->addWidget(m_nameLabel);
    m_itemsLayout->addWidget(m_title);
    m_itemsLayout->addWidget(m_dowloadDocument);
    m_itemsLayout->addWidget(m_inputArea);
    m_itemsLayout->addWidget(m_save);
    m_itemsLayout->addWidget(m_exitButton);

    m_mainLayout = new QHBoxLayout();
    m_mainLayout->addSpacerItem(m_rightSpace);
    m_mainLayout->addLayout(m_itemsLayout);

    setLayout(m_mainLayout);

    connect(m_save, &QPushButton::clicked, this, &CreateCase::onSaveClicked);
    connect(m_exitButton, &QPushButton::clicked, this, &CreateCase::onExitButtonClicked);
}

void CreateCase::onSaveClicked()
{
    emit saveCase(m_title->text(), m_inputArea->giveList());
}

void CreateCase::onExitButtonClicked()
{
    if (!m_title->text().isEmpty() || m_inputArea->count() != 0)
    {
        QMessageBox messageBox;
        messageBox.setWindowTitle("Warning");

        // Встановлення тексту та кнопок
        messageBox.setText("If you exit all input will clear. Are you sure?");
        messageBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

        int result = messageBox.exec();
        if (result == QMessageBox::Ok)
        {
            m_inputArea->clearAll();
            m_title->setText("");
            emit emitExit();
        }
    }
    else
        emit emitExit();
}
