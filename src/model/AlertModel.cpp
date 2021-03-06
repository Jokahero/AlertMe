#include "inc/model/AlertModel.hpp"

#include "core/Alert.hpp"

const int AlertModel::ActiveRole = Qt::UserRole;
const int AlertModel::DelayRole = Qt::UserRole + 1;
const int AlertModel::DesciptionRole = Qt::UserRole + 2;
const int AlertModel::NameRole = Qt::UserRole + 3;
const int AlertModel::RepetitiveRole = Qt::UserRole + 4;

AlertModel::AlertModel(QVector<Alert*> alerts, QObject *parent) : QAbstractListModel(parent), _alerts(alerts) {}

int AlertModel::rowCount(const QModelIndex &parent) const {
	Q_UNUSED(parent);

	return _alerts.size();
}

QVariant AlertModel::data(const QModelIndex &index, int role) const {
	if (!isIndexValid(index))
		return QVariant();

	int row = index.row();

	switch (role) {
		case AlertModel::ActiveRole:
			return _alerts.at(row)->isActive();
		case Qt::DisplayRole:
		case AlertModel::NameRole:
			return _alerts.at(row)->name();
		case AlertModel::DelayRole:
			return QVariant();
		case AlertModel::DesciptionRole:
			return _alerts.at(row)->description();
		case AlertModel::RepetitiveRole:
			return _alerts.at(row)->isRepetitive();
	}

	return QVariant();
}

QMap<int, QVariant> AlertModel::itemData(const QModelIndex &index) const {
	if (!isIndexValid(index))
		return QMap<int, QVariant>();

	QMap<int, QVariant> map = QAbstractListModel::itemData(index);

	Alert *alert = _alerts.at(index.row());

	map.insert(AlertModel::ActiveRole, alert->isActive());
	map.insert(AlertModel::DelayRole, QVariant()); // FIXME
	map.insert(AlertModel::DesciptionRole, alert->description());
	map.insert(AlertModel::NameRole, alert->name());
	map.insert(AlertModel::RepetitiveRole, alert->isRepetitive());

	return map;
}

bool AlertModel::isIndexValid(const QModelIndex &index) const {
	if (index.isValid()) {
		int row = index.row();
		if (row >= 0 && row < _alerts.size())
			return true;
	}
	return false;
}

bool AlertModel::setData(const QModelIndex &index, const QVariant &value, int role) {
	if (!isIndexValid(index))
		return false;

	Alert *alert = _alerts.at(index.row());

	switch (role) {
		case AlertModel::ActiveRole:
			alert->setActive(value.toBool());
			return true;
		case AlertModel::DesciptionRole:
			alert->setDescription(value.toString());
			return true;
		case AlertModel::NameRole:
			alert->setName(value.toString());
			return false;
		case AlertModel::RepetitiveRole:
			alert->setRepetitive(value.toBool());
			return true;
		default:
			return QAbstractListModel::setData(index, value, role);
	}
}

bool AlertModel::setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles) {
	if (!isIndexValid(index))
		return false;

	QAbstractListModel::setItemData(index, roles);

	Alert *alert = _alerts.at(index.row());

	alert->setActive(roles.value(AlertModel::ActiveRole).toBool());
	alert->setDescription(roles.value(AlertModel::DesciptionRole).toString());
	alert->setName(roles.value(AlertModel::NameRole).toString());
	alert->setRepetitive(roles.value(AlertModel::RepetitiveRole).toBool());

	emit dataChanged(index, index);

	return true;
}

bool AlertModel::removeRow(int row, const QModelIndex &parent) {
	if (row >= 0 && row < _alerts.size()) {
		beginRemoveRows(parent, row, row);
		_alerts.remove(row);
		emit dataChanged(createIndex(0, 0), createIndex(_alerts.size() - 1, 0));
		endRemoveRows();
		return true;
	} else
		return false;
}
