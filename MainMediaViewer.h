#pragma once
#include <QMainWindow>
#include "MediaRow.h"

namespace Ui {
class MainMediaViewer;
}
class MediaParser;
class DbPathDialog;

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

private:
    Ui::MainMediaViewer *m_ui;
    DbPathDialog *m_dbPathDlg;
    MediaParser *m_parser;
    QVector<Media> m_media;
};
