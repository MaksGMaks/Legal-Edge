#pragma once

#include <memory>
#include <QString>

struct Reader
{
    Reader();
    bool moveToDir(const QString &path);
    bool moveToDirByPath(const QString &path, const QString &to_path);
};