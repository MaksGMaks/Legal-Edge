#pragma once

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTreeView>
#include <QFileSystemModel>
#include <QModelIndex>
#include <QEvent>
#include <QMouseEvent>
#include <QMenu>
#include <QList>
#include <QLineEdit>
#include <QMessageBox>
#include <QInputDialog>
#include <QDesktopServices>
#include <QStandardPaths>
#include <QProcess>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QFileInfo>
#include <QMimeData>

class FileViewer : public QTreeView 
{
    Q_OBJECT
signals:
    void itemClicked(const QModelIndex &index, QMouseEvent *event);
    void itemsDropped(QList<QString> list);

public:
    FileViewer(QWidget *parent = nullptr);
    ~FileViewer();

    void getList(QList<QString> &list);
    QList<QString> giveList();

protected:
    QList<QString> m_list;

    void mousePressEvent(QMouseEvent *event) override;  
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;

    void showErrorDialog();  
};

class WatchCases : public QWidget
{
    Q_OBJECT

private:

    QComboBox *m_cases;
    QPushButton *m_exitButton;
    FileViewer *m_view;
    QFileSystemModel *m_caseDir;

    QList<QString> m_allCases;
    QList<QString> m_allCasesPath;

    QVBoxLayout *m_mainLayout;
    

    void openCase(const QString pathToCase);

public: 
    
    WatchCases(QWidget *parent = nullptr);
    ~WatchCases();

    void init(const bool readOnly);
    void getCases(const QList<QString> casesName, const QList<QString> casesPath);

protected slots:
    void onExitButtonClicked();
    
    void catchItems(QList<QString> list);
    void fileClicked(const QModelIndex &index, QMouseEvent *event);

    void currentCaseChanged(int index);

    void openFileTriggered(const QModelIndex &index);
    void deleteFileTriggered(const QModelIndex &index);
    void renameFileTriggered(const QModelIndex &index);

signals:
    void emitExit();
    void fileChanged(const QString &caseName, QList<QString> filesPath);
};