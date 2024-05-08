#pragma once

#include <QWidget>
#include <QListWidget>
#include <QMenu>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QFileInfo>
#include <QMimeData>
#include <QPushButton>
#include <QVBoxLayout>


#include <QMessageBox>
#include <QIcon>


class InputAreaComp : public QListWidget
{
    Q_OBJECT

private:
    bool dragInProgress = false;
    QList<QUrl> droppedFiles;

public:
    InputAreaComp(QListWidget *parent = nullptr);
    ~InputAreaComp();
    
    void clearAll();
    QList<QString> giveList();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;

    void showErrorDialog();
    void handleItemDoubleClicked(QListWidgetItem *item);

};