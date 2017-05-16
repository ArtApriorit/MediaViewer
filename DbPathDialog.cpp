#include "stdafx.h"
#include "DbPathDialog.h"
#include "ui_DbPathDialog.h"
#include <QFileDialog>

DbPathDialog::DbPathDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::DbPathDialog)
{
    m_ui->setupUi(this);
}

DbPathDialog::~DbPathDialog()
{
    delete m_ui;
}

void DbPathDialog::on_btnCancel_clicked()
{
    close();
}

void DbPathDialog::on_btnOk_clicked()
{
    emit DbPathSelected(GetFullPath());
    close();
}

QString DbPathDialog::GetFullPath()
{
    return m_ui->linePath->text();
}

void DbPathDialog::on_btnBrowse_clicked()
{
    const QString& choosenPath = QFileDialog::getOpenFileName(this, "Select data base file");
    if (!choosenPath.isEmpty())
    {
        m_ui->linePath->setText(choosenPath);
    }
}
