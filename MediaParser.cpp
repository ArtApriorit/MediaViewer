#include "MediaParser.h"
#include "stdafx.h"

namespace
{
    const char dbRequest[] = "SELECT relationalPath, mediaType, contentUrl, published FROM Media";
    QString dbFileLocationPath = "Users\\antonenko.artem\\AppData\\Roaming\\Elcomsoft\\Elcomsoft Cloud eXplorer\\Backups\\apriorit.android@gmail.com_20170320141910";
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
        media.filePath = query.value(0).toString();
        media.filePath.replace(dbFileLocationPath, QString("F:"));
        media.fileType = query.value(1).toString();
        media.hyperlink = query.value(2).toString();
        media.publishedTime = query.value(3).toInt();

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
    else
    {
        return false;
    }

}
