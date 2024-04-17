#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::init(const QVector<QWidget *> widgets, const QVector<QString> names)
{
    qDebug() << "MainWindow: init";
    this->resize(Window::WIDTH, Window::HEIGHT);

    m_tabWidget = new QTabWidget(this);

    for (int i = 0; i < widgets.size(); ++i)
        m_tabWidget->addTab(widgets[i], tr(names[i].toUtf8()));

    m_tabWidget->resize(this->size().width(), this->size().height());
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    // m_stackView->resize(this->size().width(), this->size().height());
    m_tabWidget->resize(this->size().width(), this->size().height());
}