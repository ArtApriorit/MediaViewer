#pragma once
#include <QStyledItemDelegate>
#include "MediaRow.h"

class MediaItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit MediaItemDelegate(QObject* parent, Media& media);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override;

private:
    Media m_media;
};
