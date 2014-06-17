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
#include "ui/ManageDialog.hpp"

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

    // Alerts ---------------------------------------------------------------------------
    AlertManager *manager = new AlertManager();

	/** Look around **/
	Feature::Notification* eyesNotification = new Feature::Notification("Hey, look around !");
	eyesNotification->setSystemTrayIcon(icon);

	TickTimer *eyesAlert = new TickTimer("Eyes alert", "You should look away", 900);
	eyesAlert->addFeature(new Feature::Sound("Test sound", "://sounds/poke.wav"));
	eyesAlert->addFeature(eyesNotification);

	/** Walk around **/
	Feature::Notification* bodyNotification = new Feature::Notification("Hey, walk around !");
	bodyNotification->setSystemTrayIcon(icon);

	TickTimer *bodyAlert = new TickTimer("Body alert", "You should take a walk", 3600);
	bodyAlert->addFeature(new Feature::Sound("Test sound", "://sounds/poke.wav"));
	bodyAlert->addFeature(bodyNotification);

	manager->addAlert(eyesAlert);
	manager->addAlert(bodyAlert);

	manager->start();

    // Main dialog ----------------------------------------------------------------------
    ManageDialog* dialog = new ManageDialog(manager);

    //QObject::connect(manageAction, &QAction::triggered, view, &QQuickView::show);
    QObject::connect(manageAction, &QAction::triggered, dialog, &ManageDialog::show);
    
    return application.exec();
}
