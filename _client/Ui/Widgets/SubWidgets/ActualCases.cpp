#include "ActualCases.hpp"

ActualCases::ActualCases(QWidget *parent) : QWidget(parent)
{

}

ActualCases::~ActualCases()
{

}

void ActualCases::init(const bool readOnly)
{
    m_cases = new QComboBox();
    m_exitButton = new QPushButton("Exit");
    m_view = new FileEditor();
    m_caseDir = new QFileSystemModel();
    m_caseDir->setReadOnly(readOnly);

    m_mainLayout = new QVBoxLayout();

    m_mainLayout->addWidget(m_exitButton);
    m_mainLayout->addWidget(m_cases);
    m_mainLayout->addWidget(m_view);

    setLayout(m_mainLayout);

    connect(m_exitButton, &QPushButton::clicked, this, &ActualCases::onExitButtonClicked);
    connect(m_cases, &QComboBox::currentIndexChanged, this, &ActualCases::currentCaseChanged);
    connect(m_view, &FileEditor::itemClicked, this, &ActualCases::fileClicked);
    connect(m_view, &FileEditor::itemsDropped, this, &ActualCases::catchItems);
}

void ActualCases::openCase(const QString pathToCase)
{
    m_caseDir->setRootPath(pathToCase);
    m_view->setModel(m_caseDir);
}

void ActualCases::getCases(const QList<QString> casesName, const QList<QString> casesPath)
{
    m_allCases = casesName;
    m_allCasesPath = casesPath;

    for(auto element : m_allCases)
    {
        m_cases->addItem(element);
    }
}

void ActualCases::onExitButtonClicked()
{
    emit emitExit();
}

void ActualCases::currentCaseChanged(int index)
{
    QFileSystemModel* buff = new QFileSystemModel();
    for(auto element : m_allCasesPath)
    {
        qDebug() << "DEBUG::WATCHCASES -- casePath " << element;
        qDebug() << "DEBUG::WATCHCASES -- caseName " << m_cases->itemText(index);
        qDebug() << "DEBUG::WATCHCASES -- currentPath " << QDir::currentPath();
        if(element.contains(m_cases->itemText(index)))
            buff->setRootPath(element);
    }

    m_view->setModel(m_caseDir);
    m_caseDir->setRootPath(buff->rootPath());
    QModelIndex rootIndex = m_caseDir->index(buff->rootPath());

    qDebug() << "Index of the last folder in the path:" << rootIndex;
    
    m_view->setRootIndex(m_caseDir->setRootPath(buff->fileInfo(rootIndex).absoluteFilePath()));
    

}

void ActualCases::fileClicked(const QModelIndex &index, QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        QMenu menu;
        QAction *openF = menu.addAction("Open");
        QAction *renameF = menu.addAction("Rename");
        QAction *deleteF = menu.addAction("Delete");
        connect(openF, &QAction::triggered, this, [this, index]{
            openFileTriggered(index);
        });
        connect(renameF, &QAction::triggered, this, [this, index]{
            renameFileTriggered(index);
        });
        connect(deleteF, &QAction::triggered, this, [this, index]{
            deleteFileTriggered(index);
        });
        qDebug() << "Index in menu " << index;
        menu.exec(event->globalPosition().toPoint());
    }
    else if(event->button() == Qt::LeftButton)
    {
        return;
    }
}


void ActualCases::openFileTriggered(const QModelIndex &index)
{
    qDebug() << "Index in openFile " << index;
    if (!index.isValid()) // Перевірка на дійсність індексу
        return;

    QFileSystemModel *fileSystemModel = qobject_cast<QFileSystemModel*>(m_view->model()); // Отримати модель
    if (!fileSystemModel)
        return;

    QString filePath = fileSystemModel->filePath(index); // Отримати повний шлях до файлу
    qDebug() << "File Path " << filePath;
    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath)); // Відкрити файл
}   

void ActualCases::deleteFileTriggered(const QModelIndex &index)
{
    qDebug() << "Index in deleteFile " << index;
    
    if (!index.isValid()) // Перевірка на дійсність індексу
        return;

    QFileSystemModel *fileSystemModel = qobject_cast<QFileSystemModel*>(m_view->model()); // Отримати модель
    if (!fileSystemModel)
        return;

    QString filePath = fileSystemModel->filePath(index); // Отримати повний шлях до файлу
    if (QFile::moveToTrash(filePath)) { // Видалити файл
        QMessageBox::information(this, tr("Delete Successful"), tr("File deleted successfully."));
        for(int i = 0; i < m_allCasesPath.size(); i++)
        {
            if(m_allCasesPath[i].contains(filePath))
            {
                m_allCasesPath.remove(i);
            }
        }
        emit fileChanged(m_cases->currentText(), m_allCasesPath);
    } else {
        QMessageBox::warning(this, tr("Error"), tr("Failed to delete file."));
    }
}

void ActualCases::renameFileTriggered(const QModelIndex &index)
{
    qDebug() << "Index in renameFile " << index;

    QString oldName = m_caseDir->fileName(index);
    bool ok;
    QString newName = QInputDialog::getText(this, tr("Rename File"), tr("Enter new name:"), QLineEdit::Normal, oldName, &ok);
    if (ok && !newName.isEmpty()) 
    {
        QString newPath = m_caseDir->filePath(index).section('/', 0, -2) + '/' + newName;
        if (QFile::rename(m_caseDir->filePath(index), newPath)) 
        {
            QMessageBox::information(this, tr("Rename Successful"), tr("File renamed successfully."));
            m_caseDir->setRootPath(m_caseDir->rootPath()); // Оновлюємо модель, щоб побачити зміни

            for(int i = 0; i < m_allCasesPath.size(); i++)
            {
                if(m_allCasesPath[i].contains(oldName))
                {
                    m_allCasesPath[i] = newPath;
                }
            }
            emit fileChanged(m_cases->currentText(), m_allCasesPath);
        } else {
            QMessageBox::warning(this, tr("Error"), tr("Failed to rename file."));
        }
    }
}

void ActualCases::catchItems(QList<QString> list)
{
    qDebug() << "Before";
    for(auto element : m_allCasesPath)
        qDebug() << m_allCasesPath;

    m_allCasesPath = list;

    qDebug() << "After";
    for(auto element : m_allCasesPath)
        qDebug() << m_allCasesPath;
}


FileEditor::FileEditor(QWidget *parent) : QTreeView(parent) 
{
    setAcceptDrops(true);
    setDragEnabled(false);
    setDragDropMode(QAbstractItemView::DropOnly);
}

FileEditor::~FileEditor()
{

}

void FileEditor::mousePressEvent(QMouseEvent *event) 
{
    QModelIndex index = indexAt(event->pos());
    if (index.isValid()) 
    {
        emit itemClicked(index, event);
    }
    QTreeView::mousePressEvent(event);
}


void FileEditor::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
    event->acceptProposedAction();
}

void FileEditor::dropEvent(QDropEvent *event)
{
    qDebug() << "DEBUG: TEST FILE DROP: get in dropEvent";
    if(event->source() == this) return;

    
    qDebug() << "DEBUG: TEST FILE DROP: get in dropEvent and get source" << event->mimeData()->urls();
    QList<QUrl> m_items = event->mimeData()->urls();
    
    for(auto element : m_items)
    {
        QString fileName = QFileInfo(element.toLocalFile()).fileName();
        
        bool isInside = false;
        for(auto pathes : m_list)
        {
            if(pathes.contains(element.toString()))
                isInside = true;
        }
        if(!isInside)
        {
            m_list.append(element.toString());
        }
        else
        {
            this->showErrorDialog();
        }
    }
    emit itemsDropped(m_list);
    
}

void FileEditor::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
    event->acceptProposedAction();
}

void FileEditor::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void FileEditor::showErrorDialog()
{
    QMessageBox messageBox;
    messageBox.setIcon(QMessageBox::Warning);
    messageBox.setWindowTitle("Error");
    messageBox.setText("File with the same name already exists");
    messageBox.setStandardButtons(QMessageBox::Ok);
    messageBox.exec();
}

void FileEditor::getList(QList<QString> &list)
{
    m_list = list;
}

QList<QString> FileEditor::giveList()
{
    return m_list;
}