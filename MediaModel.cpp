#include "MediaModel.h"
#include <QSize>

MediaModel::MediaModel(QObject* parent, QVector<Media> &media)
    : QAbstractListModel(parent)
    , m_mediaVt(media)
{
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
//        return QVariant::fromValue(m_mediaVt[index.row()]);
        return QVariant::fromValue(m_mediaVt[index.row()].filePath);

    case Qt::SizeHintRole:
        return QSize(220, 280);

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
