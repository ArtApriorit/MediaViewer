#pragma once
#include "stdafx.h"

struct Media
{
    QString name;
    QString filePath;
    QString fileType;
    QString hyperlink;
    time_t publishedTime;
};

Q_DECLARE_METATYPE(Media)
