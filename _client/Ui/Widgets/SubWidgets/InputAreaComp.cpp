#include "InputAreaComp.hpp"

InputAreaComp::InputAreaComp(QListWidget *parent) : QListWidget(parent)
{
    setAcceptDrops(true);
    setDragEnabled(false);
    setDragDropMode(QAbstractItemView::DropOnly);
    connect(this, &QListWidget::itemDoubleClicked, this, &InputAreaComp::handleItemDoubleClicked);
    setStyleSheet("QListWiget { "
                  "background-color: #bbbbbb; "
                  "color: #000; "
                  "border: 2px solid #737373; "
                  "border-radius: 15%; "
                  "padding: 10px; "
                  "font-size: 18px; }");
}

InputAreaComp::~InputAreaComp()
{
}

void InputAreaComp::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
    event->acceptProposedAction();
}

void InputAreaComp::dropEvent(QDropEvent *event)
{
    qDebug() << "DEBUG: TEST FILE DROP: get in dropEvent";
    if (event->source() == this)
        return;

    qDebug() << "DEBUG: TEST FILE DROP: get in dropEvent and get source" << event->mimeData()->urls();
    QList<QUrl> m_items = event->mimeData()->urls();

    for (auto element : m_items)
    {
        QString fileName = QFileInfo(element.toLocalFile()).fileName();

        if (this->findItems(fileName, Qt::MatchExactly).empty())
        {
            droppedFiles.append(element);
            this->addItem(fileName);
        }
        else
        {
            this->showErrorDialog();
        }
    }
}

void InputAreaComp::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
    event->acceptProposedAction();
}

void InputAreaComp::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void InputAreaComp::showErrorDialog()
{
    QMessageBox messageBox;
    messageBox.setIcon(QMessageBox::Warning);
    messageBox.setWindowTitle("Error");
    messageBox.setText("File with the same name already exists");
    messageBox.setStandardButtons(QMessageBox::Ok);
    messageBox.exec();
}

void InputAreaComp::handleItemDoubleClicked(QListWidgetItem *item)
{
    QMessageBox messageBox;
    messageBox.setWindowTitle("Warning");

    // Встановлення тексту та кнопок
    messageBox.setText("File " + item->text() + " will be removed from case. Are you sure?");
    messageBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

    int result = messageBox.exec();
    if (result == QMessageBox::Ok)
    {
        this->removeItemWidget(item);
        for (auto element : droppedFiles)
        {
            if (QFileInfo(element.toLocalFile()).fileName() == item->text())
            {
                droppedFiles.removeOne(element);
            }
        }
        delete item;
    }
}

void InputAreaComp::clearAll()
{
    this->clear();
    droppedFiles.clear();
}

QList<QString> InputAreaComp::giveList()
{
    QList<QString> list;
    for (auto element : droppedFiles)
        list.append(element.toString());

    return list;
}