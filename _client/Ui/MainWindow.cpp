#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    m_stackView = new QStackedWidget(this);
    this->showMaximized();
}

MainWindow::~MainWindow()
{
}

void MainWindow::init()
{
    this->resize(Window::WIDTH, Window::HEIGHT);
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    m_stackView->resize(this->size().width(), this->size().height());
}
