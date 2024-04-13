#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->init();
    m_stackView = new QStackedWidget(this);
}

MainWindow::~MainWindow()
{
}

void MainWindow::init()
{
    qDebug() << "MainWindow: init";
    this->resize(Window::WIDTH, Window::HEIGHT);
    m_stackView = new QStackedWidget(this);

    QWidget *test = new QWidget(this);
    m_stackView->addWidget(test);
    qDebug() << "MainWindow: add widget, index - " << m_stackView->currentIndex();
    QWidget *test1 = new QWidget(this);
    m_stackView->addWidget(test1);
    m_stackView->setCurrentIndex(1);
    qDebug() << "MainWindow: add widget, index - " << m_stackView->currentIndex();

    m_stackView->resize(this->size().width(), this->size().height());

    // Menu
    // QMenu * m_caseManagment = createMenu(tr("Case Managment"), 0);

    // qDebug() << "MainWindow: add case managment";
    // m_mainMenuBar->addMenu(m_caseManagment);

    // qDebug() << "MainWindow: set menubar";
    // this->setMenuBar(m_mainMenuBar);
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    m_stackView->resize(this->size().width(), this->size().height());
}

// void MainWindow::pageHandler(int index)
// {
//     switch (index)
//     {
//     case 0:
//         m_stackView->setCurrentIndex(index);
//         break;
//     default:
//         break;
//     }
//     qDebug() << "MainWindow: stackview index - " << m_stackView->currentIndex();
// }

// QMenu *MainWindow::createMenu(const QString &text, int index)
// {
//     QMenu *menu = new QMenu(text);

//     QAction *action = new QAction(text, this);
//     connect(action, &QAction::triggered, this, MainWindow::pageHandler);

//     menu->addAction(action);
//     return menu;
// }
