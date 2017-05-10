#pragma once
#include "MediaRow.h"
#include <QWidget>

namespace Ui {
class ItemWidget;
}

class ItemWidget : public QWidget
{
    Q_OBJECT

public:
    ItemWidget(QWidget *parent, Media media);
    ~ItemWidget();

private:
    Ui::ItemWidget* m_ui;
    Media m_media;
};
