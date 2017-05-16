#pragma once
#include <QDialog>

namespace Ui {
class DbPathDialog;
}

class DbPathDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DbPathDialog(QWidget *parent = 0);
    ~DbPathDialog();

signals:
    void DbPathSelected(const QString &path);

private slots:
    void on_btnCancel_clicked();
    void on_btnOk_clicked();
    void on_btnBrowse_clicked();

private:
    QString GetFullPath();

private:
    Ui::DbPathDialog *m_ui;
};

