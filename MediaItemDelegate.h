#pragma once
#include <memory>
#include <map>
#include <QStyledItemDelegate>
#include "MediaRow.h"

class MediaItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    MediaItemDelegate(QObject* parent, const QVector<Media>& media);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override;

private:
    std::map<QString, std::unique_ptr<QWidget>> m_mediaWidgets;
};
