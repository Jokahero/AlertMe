#include <QAction>
#include <QApplication>
#include <QMenu>
#include <QtQuick/QQuickView>
#include <QSystemTrayIcon>
#include <QTranslator>

#include <iostream>

#include "core/AlertManager.hpp"
#include "core/features/Sound.hpp"
#include "core/features/Notification.hpp"
#include "core/TickTimer.hpp"

int main(int argc, char** argv) {
    QApplication application(argc, argv);
    application.setQuitOnLastWindowClosed(false);

    // System tray icon -----------------------------------------------------------------

	QSystemTrayIcon *icon = new QSystemTrayIcon(QIcon(":///icons/images/logo.png"));
	icon->show();

    QMenu* menu = new QMenu();
    QAction* manageAction = menu->addAction(QIcon(":///icons/images/manage.png"), QAction::tr("Ma&nage"));
    menu->addSeparator();
    QAction* quitAction = menu->addAction(QIcon(":///icons/images/quit.png"), QAction::tr("&Quitter"));

    icon->setContextMenu(menu);

    QObject::connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);

    // Main dialog ----------------------------------------------------------------------

    QQuickView* view = new QQuickView();
    view->setSource(QUrl::fromLocalFile("ui/MainWidget.qml"));
    //view.show();

    QObject::connect(manageAction, &QAction::triggered, view, &QQuickView::show);

    // Alerts ---------------------------------------------------------------------------

    AlertManager *manager = new AlertManager();

	TickTimer *myAlert = new TickTimer("My alert", "Description of my alert", 60);
	myAlert->addFeature(new Feature::Sound("Test sound", "://sounds/poke.wav"));
	Feature::Notification* notification = new Feature::Notification("Hey, wake up !");
	notification->setSystemTrayIcon(icon);
	myAlert->addFeature(notification);

	manager->addAlert(myAlert);
	manager->start();
    
    return application.exec();
}
