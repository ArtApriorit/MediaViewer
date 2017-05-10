#include "ItemWidget.h"
#include "ui_ItemWidget.h"
#include <QDateTime>

ItemWidget::ItemWidget(QWidget* parent, Media media)
    : QWidget(parent)
    , m_media(media)

{
    m_ui = new Ui::ItemWidget;
    m_ui->setupUi(this);

    QPixmap pixmap(m_media.filePath);
    m_ui->lblImage->setPixmap(pixmap);

    const QDateTime dt = QDateTime::fromTime_t(m_media.publishedTime);
    const QString textdate = dt.toString(Qt::TextDate);
    m_ui->lineDate->setText(textdate);
    m_ui->lineDate->setReadOnly(true);
    m_ui->lineDate->show();

    m_ui->lblUrl->setText(m_media.hyperlink);
    m_ui->lblUrl->setOpenExternalLinks(true);
}

ItemWidget::~ItemWidget()
{
    delete m_ui;
}
