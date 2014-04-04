#include <QAction>
#include <QApplication>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QTranslator>

#include <iostream>

#include "core/AlertManager.hpp"
#include "core/features/Sound.hpp"
#include "core/features/Notification.hpp"
#include "core/TickTimer.hpp"

int main(int argc, char** argv) {
    QApplication application(argc, argv);

	QSystemTrayIcon *icon = new QSystemTrayIcon(QIcon(":///icons/images/logo.png"));
	icon->show();

    QMenu* menu = new QMenu();
    QAction* quitAction = menu->addAction(QAction::tr("&Quitter"));
    icon->setContextMenu(menu);

    QObject::connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);

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
