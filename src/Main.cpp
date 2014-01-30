#include <QApplication>

#include "inc/AlertManager.hpp"
#include "inc/Sound.hpp"
#include "inc/TickTimer.hpp"

int main(int argc, char** argv) {
    QApplication application(argc, argv);

	AlertManager *manager = new AlertManager();

	TickTimer *myAlert = new TickTimer("My alert", "Description of my alert", 45);
	myAlert->setSound(new Sound("Test sound", "://sounds/poke.wav"));

	manager->addAlert(myAlert);
	manager->start();

    return application.exec();
}
