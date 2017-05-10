#include "MediaItemDelegate.h"
#include "ItemWidget.h"

#include <QPaintDevice>
#include <QPainter>

namespace
{
    const int frameWidth = 1;
}

MediaItemDelegate::MediaItemDelegate(QObject *parent, Media& media)
    : QStyledItemDelegate(parent)
    , m_media(media)
{  
}

void MediaItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QPen pen;
    pen.setWidth(frameWidth);
    painter->setPen(pen);
    painter->drawRect(option.rect);

    ItemWidget item(nullptr, m_media);
//    ItemWidget item(nullptr, index.data());
    item.setGeometry(option.rect);

    QPaintDevice* originalPaintDevice = painter->device();
    painter->end();
    item.render(painter->device(), QPoint(option.rect.x(), option.rect.y()), QRegion(0, 0, option.rect.width(), option.rect.height()), QWidget::RenderFlag::DrawChildren);
    painter->begin(originalPaintDevice);
}

QSize MediaItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return index.data(Qt::SizeHintRole).toSize();
}
