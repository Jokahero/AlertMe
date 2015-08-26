#include "inc/model/AlertModel.hpp"

#include "core/AAlert.hpp"

#define UNUSED(x) (void)x

AlertModel::AlertModel(QVector<AAlert*> alerts, QObject *parent) : QAbstractListModel(parent), _alerts(alerts) {}

int AlertModel::rowCount(const QModelIndex &parent) const {
    UNUSED(parent);

    return _alerts.size();
}

QVariant AlertModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return 0;

    int row = index.row();
    if (row < 0 || row >= _alerts.size())
        return 0;

    switch (role) {
        case Qt::DisplayRole:
            return _alerts.at(row)->name();
    }

    return 0;
}
