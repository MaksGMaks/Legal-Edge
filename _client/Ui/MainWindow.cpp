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

    // // Widget1
    // QWidget *test = new QWidget(this);
    // QLabel *testLabel = new QLabel("TEST 1");
    // QHBoxLayout *testLay = new QHBoxLayout(test);
    // testLay->addWidget(testLabel);
    // test->setLayout(testLay);
    // m_stackView->addWidget(test);
    // qDebug() << "MainWindow: add widget, index - " << m_stackView->currentIndex();

    // // Widget2
    // QWidget *test1 = new QWidget(this);
    // QLabel *testLabel1 = new QLabel("TEST 2");
    // QHBoxLayout *test1Lay = new QHBoxLayout(test1);
    // test1Lay->addWidget(testLabel1);
    // test1->setLayout(test1Lay);

    // m_stackView->addWidget(test1);
    // m_stackView->setCurrentIndex(1);
    // qDebug() << "MainWindow: add widget, index - " << m_stackView->currentIndex();

    // m_stackView->resize(this->size().width(), this->size().height());

    // // Menu
    // m_mainMenuBar = new QMenuBar(this);
    // this->setMenuBar(m_mainMenuBar);

    // qDebug() << "MainWindow:: create Menu";
    // createMenu(m_mainMenuBar, tr("Case Managment"), 0);
    // createMenu(m_mainMenuBar, tr("Helper"), 1);
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    m_stackView->resize(this->size().width(), this->size().height());
}

// void MainWindow::pageHandler(int index)
// {
//     qDebug() << "Action triggered with index: " << index;
//     switch (index)
//     {
//     case 0:
//         m_stackView->setCurrentIndex(index);
//         break;
//     case 1:
//         m_stackView->setCurrentIndex(index);
//         break;
//     default:
//         break;
//     }
//     qDebug() << "MainWindow: stackview index - " << m_stackView->currentIndex();
// }

// void MainWindow::createMenu(QMenuBar *menu, const QString &text, int index)
// {
//     qDebug() << "MainWindow::createMenu: add action with index - " << index;
//     QAction *action = new QAction(text);
//     connect(action, &QAction::triggered, menu, [menu, this, index]()
//             { pageHandler(index); });

//     menu->addAction(action);
// }
