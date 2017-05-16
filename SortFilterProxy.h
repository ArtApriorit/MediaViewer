#pragma once
#include <QObject>
#include <QSortFilterProxyModel>

struct Media;

class SortFilterProxy : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    SortFilterProxy(QObject* parent = 0);

    void SetNameFilter(const QString& nameFilter);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    QString m_nameFilter;
};

