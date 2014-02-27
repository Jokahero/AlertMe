#include <QApplication>

#include <QSystemTrayIcon>

#include <iostream>

#include "core/AlertManager.hpp"
#include "core/Sound.hpp"
#include "core/TickTimer.hpp"

int main(int argc, char** argv) {
    QApplication application(argc, argv);

	AlertManager *manager = new AlertManager();

	TickTimer *myAlert = new TickTimer("My alert", "Description of my alert", 900);
	myAlert->setSound(new Sound("Test sound", "://sounds/poke.wav"));

	manager->addAlert(myAlert);
	manager->start();

    std::cout << (QSystemTrayIcon::isSystemTrayAvailable() ? "true" : "false") << std::endl;
    
    QSystemTrayIcon *icon = new QSystemTrayIcon(QIcon(":///icons/trayIcon.png"));
    icon->show();
    icon->showMessage("Hey !", "Wake up !");
    
    return application.exec();
}
