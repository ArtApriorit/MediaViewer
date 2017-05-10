#include "MainMediaViewer.h"
#include "ui_MainMediaViewer.h"
#include "MediaParser.h"
#include "DbPathDialog.h"
#include "MediaModel.h"
#include "MediaItemDelegate.h"

namespace
{
    QString dbPath = "F:\\GooglePhotos\\GoogleMedia.db";
}

MainMediaViewer::MainMediaViewer(QWidget *parent) :
    QMainWindow(parent)
{
    m_ui = new Ui::MainMediaViewer;
    m_ui->setupUi(this);
    m_parser = new MediaParser(dbPath);
    m_dbPathDlg = new DbPathDialog(this);

    m_ui->listView->setFlow(QListView::LeftToRight);
    m_ui->listView->setResizeMode(QListView::Adjust);
    m_ui->listView->setSpacing(8);
    m_ui->listView->setViewMode(QListView::IconMode);

    m_parser->Parse(m_media);

    MediaModel* model = new MediaModel(this, m_media);
    m_ui->listView->setModel(model);

    MediaItemDelegate* delegate = new MediaItemDelegate(this, m_media[0]);
    m_ui->listView->setItemDelegate(delegate);

    connect(m_dbPathDlg, &DbPathDialog::DbPathSelected, this, &MainMediaViewer::onDbPathSelected);
}

MainMediaViewer::~MainMediaViewer()
{
    delete m_ui;
}

void MainMediaViewer::onDbPathSelected(const QString &path)
{
    m_parser->setDbPath(path);
    m_parser->Parse(m_media);
}

void MainMediaViewer::on_btnOpen_clicked()
{
    m_dbPathDlg->show();
}
