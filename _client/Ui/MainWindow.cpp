#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
}

void MainWindow::init()
{
    this->resize(Window::WIDTH, Window::HEIGHT);
}