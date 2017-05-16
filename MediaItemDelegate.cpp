#include "stdafx.h"
#include "MediaItemDelegate.h"
#include "ItemWidget.h"
#include "ItemWidget.h"


MediaItemDelegate::MediaItemDelegate(QObject *parent, const QVector<Media>& media)
    : QStyledItemDelegate(parent)
{
    for (int i = 0; i < media.size(); i++)
    {
        m_mediaWidgets[media[i].filePath] = std::unique_ptr<ItemWidget>(new ItemWidget(nullptr, media[i]));
    }
}

void MediaItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QPen pen;
    painter->setPen(pen);
    painter->drawRect(option.rect);

    const auto& widgetIt = m_mediaWidgets.find(index.data().value<Media>().filePath);
    QWidget& item = *(widgetIt->second);
    item.setGeometry(option.rect);

    QPaintDevice* originalPaintDevice = painter->device();
    painter->end();
    item.render(painter->device(), QPoint((option.rect.x() + 15), (option.rect.y()) + 55), QRegion(0, 0, option.rect.width(), option.rect.height()), QWidget::RenderFlag::DrawChildren);
    painter->begin(originalPaintDevice);
}

QSize MediaItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return index.data(Qt::SizeHintRole).toSize();
}
