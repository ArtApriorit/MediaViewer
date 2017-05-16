#pragma once
#include <QAbstractTableModel>
#include "MediaRow.h"

class MediaModel : public QAbstractListModel
{
    Q_OBJECT

public:
    MediaModel(QObject *parent, QVector<Media>& media);

    void SetSortNameAscending();
    void SetSortNameDescending();
    void SetSortLatestTime();

    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

private:
    QVector<Media> m_mediaVt;
    bool (*m_sortFn)(const Media &left, const Media &right);
};
