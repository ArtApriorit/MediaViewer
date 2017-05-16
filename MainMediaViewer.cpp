#include "stdafx.h"
#include "MainMediaViewer.h"
#include "ui_MainMediaViewer.h"
#include "MediaParser.h"
#include "DbPathDialog.h"
#include "MediaModel.h"
#include "MediaItemDelegate.h"
#include "SortFilterProxy.h"

namespace
{
//    QString dbPath = "F:\\GooglePhotos\\GoogleMedia.db";
}

MainMediaViewer::MainMediaViewer(QWidget *parent) :
    QMainWindow(parent)
  , m_model(nullptr)
  , m_proxyModel(new SortFilterProxy(this))
{
    m_ui = new Ui::MainMediaViewer;
    m_ui->setupUi(this);
    m_parser = new MediaParser("");
    m_dbPathDlg = new DbPathDialog(this);

    m_ui->listView->setFlow(QListView::LeftToRight);
    m_ui->listView->setResizeMode(QListView::Adjust);
    m_ui->listView->setSpacing(8);
    m_ui->listView->setViewMode(QListView::IconMode);

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

    m_model = new MediaModel(this, m_media);
    m_proxyModel->setSourceModel(m_model);
    m_ui->listView->setModel(m_proxyModel);

    MediaItemDelegate* delegate = new MediaItemDelegate(this, m_media);
    m_ui->listView->setItemDelegate(delegate);
}

void MainMediaViewer::on_btnOpen_clicked()
{
    m_dbPathDlg->show();
}

void MainMediaViewer::on_bntSortAZ_clicked()
{
    m_model->SetSortNameAscending();
    m_model->sort(0);
}

void MainMediaViewer::on_btnSortZA_clicked()
{
    m_model->SetSortNameDescending();
    m_model->sort(0);
}

void MainMediaViewer::on_btnSortCreation_clicked()
{
    m_model->SetSortLatestTime();
    m_model->sort(0);
}

void MainMediaViewer::on_lineSearch_textChanged(const QString &arg1)
{
    m_proxyModel->SetNameFilter(arg1);
}
