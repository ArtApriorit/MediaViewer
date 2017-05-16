#include "stdafx.h"
#include "ItemWidget.h"
#include "ui_ItemWidget.h"
#include <QDateTime>

ItemWidget::ItemWidget(QWidget* parent, const Media& media)
    : QWidget(parent)

{
    m_ui = new Ui::ItemWidget;
    m_ui->setupUi(this);

    QPixmap pixmap(media.filePath);
    m_ui->lblImage->setPixmap(pixmap.scaled(200, 200));

    const QDateTime dt = QDateTime::fromTime_t(media.publishedTime);
    const QString textdate = dt.toString(Qt::TextDate);
    m_ui->lineDate->setText(textdate);
    m_ui->lineDate->setReadOnly(true);
    m_ui->lineDate->show();

    m_ui->lblUrl->setText(media.hyperlink);
    m_ui->lblUrl->setOpenExternalLinks(true);
}

ItemWidget::~ItemWidget()
{
    delete m_ui;
}
