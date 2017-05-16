#include "stdafx.h"
#include "MediaModel.h"
#include <QSize>

namespace
{
    bool SortNameAscending(const Media &left, const Media &right)
    {
        return left.name < right.name;
    }

    bool SortNameDescending(const Media &left, const Media &right)
    {
        return left.name > right.name;
    }

    bool SortLatestTime(const Media &left, const Media &right)
    {
        return left.publishedTime > right.publishedTime;
    }
}

MediaModel::MediaModel(QObject* parent, QVector<Media> &media)
    : QAbstractListModel(parent)
    , m_mediaVt(media)
{
}

void MediaModel::SetSortNameAscending()
{
    m_sortFn = SortNameAscending;
}

void MediaModel::SetSortNameDescending()
{
    m_sortFn = SortNameDescending;
}

void MediaModel::SetSortLatestTime()
{
    m_sortFn = SortLatestTime;
}

void MediaModel::sort(int column, Qt::SortOrder)
{
    if (m_sortFn)
    {
        qSort(m_mediaVt.begin(), m_mediaVt.end(), m_sortFn);
        QModelIndex top = createIndex(0, 0, nullptr);
        QModelIndex bottom = createIndex(m_mediaVt.size(), 0, nullptr);
        emit dataChanged(top, bottom, {Qt::DisplayRole});
    }
}

QVariant MediaModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

QVariant MediaModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch (role)
    {
    case Qt::DisplayRole:
        return QVariant::fromValue(m_mediaVt[index.row()]);

    case Qt::SizeHintRole:
        return QSize(230, 270);

    default:
        return QVariant();
    }
}

int MediaModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_mediaVt.size();
}
