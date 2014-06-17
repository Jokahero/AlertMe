#include "ui/ManageDialog.hpp"

#include "core/AAlert.hpp"
#include "core/AlertManager.hpp"

#include <QQmlContext>
#include <QQuickItem>
#include <QQuickView>

#include <iostream>

ManageDialog::ManageDialog(AlertManager* manager) : QQuickView() {
    setResizeMode(QQuickView::SizeRootObjectToView);

    QList<QObject*> model;
    for (AAlert* alert : manager->getAlerts())
        model.append(alert);
    rootContext()->setContextProperty("alerts", QVariant::fromValue(model));
    setSource(QUrl("qrc:/ui/MainWidget.qml"));
}
