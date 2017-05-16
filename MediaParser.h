#pragma once
#include "stdafx.h"
#include "MediaRow.h"

class MediaParser
{
public:
    explicit MediaParser(const QString &backupPath);
    ~MediaParser();
    void Parse(QVector<Media> &media_vt);
    void setDbPath(const QString &path);

private:
    bool InitializeDataBase();

private:
    QString m_backupPath;
    QSqlDatabase m_db;
};
