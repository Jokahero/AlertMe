#ifndef ALERTMODEL_H
#define ALERTMODEL_H

#include <QAbstractListModel>
#include <QVector>

class AAlert;

class AlertModel : public QAbstractListModel {
public:
    AlertModel(QVector<AAlert*> alerts, QObject *parent = 0);

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    //virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

signals:

public slots:

private:
    QVector<AAlert*> _alerts;
};

#endif // ALERTMODEL_H
