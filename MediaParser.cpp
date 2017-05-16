#include "stdafx.h"
#include "MediaParser.h"
#include <QFileInfo>

namespace
{
    const char dbRequest[] = "SELECT relationalPath, mediaType, contentUrl, published FROM Media";
}

MediaParser::MediaParser(const QString &backupPath)
    :m_backupPath(backupPath)
{
}

MediaParser::~MediaParser()
{
    if(m_db.isOpen())
    {
        m_db.close();;
    }
}

void MediaParser::Parse(QVector<Media> &media_vt)
{
    if (!InitializeDataBase())
    {
        return;
    }

    QSqlQuery query;
    query.exec(dbRequest);

    while (query.next())
    {
        Media media;
        media.filePath = "C:\\" + query.value(0).toString();
        media.fileType = query.value(1).toString();
        media.hyperlink = query.value(2).toString();
        media.publishedTime = query.value(3).toInt();
        media.name = QFileInfo(media.filePath).fileName();

        media_vt.push_back(media);
    }
}


void MediaParser::setDbPath(const QString &path)
{
    m_backupPath = path;
}

bool MediaParser::InitializeDataBase()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(m_backupPath);
    if (m_db.open())
    {
        return true;
    }

    return false;
}
