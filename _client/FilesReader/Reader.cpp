#include "Reader.hpp"

#include <QFileInfo>
#include <QFile>
#include <QDebug>
#include <QDir>

#define PATH "../../files"
#define PDF_PATH PATH "/pdf"
#define DOCX_PATH PATH "/docx"
// write check of existing dirs and if not exist -> create it

Reader::Reader()
{
    QDir dir;
    if (!dir.exists(PDF_PATH))
    {
        dir.mkpath(PDF_PATH);
        dir.mkpath(DOCX_PATH);
    }
}

bool Reader::moveToDir(const QString &path)
{
    QFile sourceFile(path);
    if (!sourceFile.exists())
    {
        return false;
    }
    QFileInfo fileInfo(path);
    QString fileExtension = fileInfo.suffix();
    if (fileExtension == "pdf")
    {
        sourceFile.copy(PDF_PATH);
    }
    if (fileExtension == "doc" || fileExtension == "docx")
    {
        sourceFile.copy(DOCX_PATH);
    }
    return true;
}