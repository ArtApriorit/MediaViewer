#pragma once
#include "stdafx.h"

enum MediaType
{
    Image,
    Gif,
    Video
};

struct Media
{
    QString filePath;
    QString fileType;
    QString hyperlink;
    time_t publishedTime;
};
