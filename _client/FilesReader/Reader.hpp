#pragma once

#include <memory>
#include <QString>

struct Reader
{
    Reader();
    bool moveToDir(const QString &path);
};