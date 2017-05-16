#include "stdafx.h"
#include "SortFilterProxy.h"
#include "MediaRow.h"

SortFilterProxy::SortFilterProxy(QObject* parent)
: QSortFilterProxyModel(parent)
{}

void SortFilterProxy::SetNameFilter(const QString& nameFilter)
{
    m_nameFilter = nameFilter;
    invalidate();
}

bool SortFilterProxy::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    if (m_nameFilter.isEmpty())
    {
        return true;
    }

    const QModelIndex& index0 = sourceModel()->index(sourceRow, 0, sourceParent);
    const Media& m = index0.data().value<Media>();
    return m.name.contains(m_nameFilter, Qt::CaseInsensitive);
}
