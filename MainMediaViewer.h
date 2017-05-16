#pragma once
#include <QMainWindow>
#include "MediaRow.h"

namespace Ui {
class MainMediaViewer;
}
class MediaParser;
class DbPathDialog;
class SortFilterProxy;
class MediaModel;

class MainMediaViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMediaViewer(QWidget *parent = 0);
    ~MainMediaViewer();

public slots:
    void onDbPathSelected(const QString &path);

private slots:
    void on_btnOpen_clicked();
    void on_bntSortAZ_clicked();
    void on_btnSortZA_clicked();
    void on_btnSortCreation_clicked();
    void on_lineSearch_textChanged(const QString &arg1);

private:
    Ui::MainMediaViewer *m_ui;
    DbPathDialog *m_dbPathDlg;
    MediaParser *m_parser;
    QVector<Media> m_media;
    MediaModel* m_model;
    SortFilterProxy* m_proxyModel;
};
