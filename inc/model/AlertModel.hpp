#ifndef ALERTMODEL_H
#define ALERTMODEL_H

#include <QAbstractListModel>
#include <QVector>

class AAlert;

class AlertModel : public QAbstractListModel {
public:
	static const int ActiveRole = Qt::UserRole;
	static const int DelayRole = Qt::UserRole + 1;
	static const int DesciptionRole = Qt::UserRole + 2;
	static const int NameRole = Qt::UserRole + 3;
	static const int RepetitiveRole = Qt::UserRole + 4;

	AlertModel(QVector<AAlert*> alerts, QObject *parent = 0);

	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	virtual QMap<int, QVariant> itemData(const QModelIndex &index) const;

	virtual bool setData(const QModelIndex &index, const QVariant &value, int role);
	virtual bool setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles);

signals:

public slots:

private:
	QVector<AAlert*> _alerts;

	bool isIndexValid(const QModelIndex &index) const;
};

#endif // ALERTMODEL_H
