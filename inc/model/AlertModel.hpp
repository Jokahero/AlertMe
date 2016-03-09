#ifndef ALERTMODEL_H
#define ALERTMODEL_H

#include <QAbstractListModel>
#include <QVector>

class Alert;

class AlertModel : public QAbstractListModel {
public:
	static const int ActiveRole;
	static const int DelayRole;
	static const int DesciptionRole;
	static const int NameRole;
	static const int RepetitiveRole;

	explicit AlertModel(QVector<Alert*> alerts, QObject *parent = 0);

	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	virtual QMap<int, QVariant> itemData(const QModelIndex &index) const override;

	virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
	virtual bool setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles) override;

	virtual bool removeRow(int row, const QModelIndex &parent = QModelIndex());

private:
	QVector<Alert*> _alerts;

	bool isIndexValid(const QModelIndex &index) const;
};

#endif // ALERTMODEL_H
