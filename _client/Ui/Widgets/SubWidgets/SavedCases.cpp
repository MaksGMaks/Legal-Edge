#include "SavedCases.hpp"

SavedCases::SavedCases(QWidget *parent) : QWidget(parent)
{

}

SavedCases::~SavedCases()
{

}

void SavedCases::init(const bool readOnly)
{
    m_cases = new QComboBox();
    m_exitButton = new QPushButton("Exit");
    m_view = new FileViewer();
    m_caseDir = new QFileSystemModel();
    m_caseDir->setReadOnly(readOnly);

    m_mainLayout = new QVBoxLayout();

    m_mainLayout->addWidget(m_exitButton);
    m_mainLayout->addWidget(m_cases);
    m_mainLayout->addWidget(m_view);

    setLayout(m_mainLayout);

    connect(m_exitButton, &QPushButton::clicked, this, &SavedCases::onExitButtonClicked);
    connect(m_cases, &QComboBox::currentIndexChanged, this, &SavedCases::currentCaseChanged);
    connect(m_view, &FileViewer::itemClicked, this, &SavedCases::fileClicked);
    connect(m_view, &FileViewer::itemsDropped, this, &SavedCases::catchItems);
}

void SavedCases::openCase(const QString pathToCase)
{
    m_caseDir->setRootPath(pathToCase);
    m_view->setModel(m_caseDir);
}

void SavedCases::getCases(const QList<QString> casesName, const QList<QString> casesPath)
{
    m_allCases = casesName;
    m_allCasesPath = casesPath;

    for(auto element : m_allCases)
    {
        m_cases->addItem(element);
    }
}

void SavedCases::onExitButtonClicked()
{
    emit emitExit();
}

void SavedCases::currentCaseChanged(int index)
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

void SavedCases::fileClicked(const QModelIndex &index, QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        QMenu menu;
        QAction *openF = menu.addAction("Open");
        connect(openF, &QAction::triggered, this, [this, index]{
            openFileTriggered(index);
        });
        qDebug() << "Index in menu " << index;
        menu.exec(event->globalPosition().toPoint());
    }
    else if(event->button() == Qt::LeftButton)
    {
        return;
    }
}


void SavedCases::openFileTriggered(const QModelIndex &index)
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

void SavedCases::catchItems(QList<QString> list)
{
    qDebug() << "Before";
    for(auto element : m_allCasesPath)
        qDebug() << m_allCasesPath;

    m_allCasesPath = list;

    qDebug() << "After";
    for(auto element : m_allCasesPath)
        qDebug() << m_allCasesPath;
}


FileViewer::FileViewer(QWidget *parent) : QTreeView(parent) 
{
    setAcceptDrops(true);
    setDragEnabled(false);
    setDragDropMode(QAbstractItemView::DropOnly);
}

FileViewer::~FileViewer()
{

}

void FileViewer::mousePressEvent(QMouseEvent *event) 
{
    QModelIndex index = indexAt(event->pos());
    if (index.isValid()) 
    {
        emit itemClicked(index, event);
    }
    QTreeView::mousePressEvent(event);
}

