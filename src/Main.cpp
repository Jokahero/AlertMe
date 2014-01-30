#include <QApplication>

#include "core/AlertManager.hpp"
#include "core/TickTimer.hpp"

int main(int argc, char** argv) {
    QApplication application(argc, argv);

	AlertManager *manager = new AlertManager();

	TickTimer *myAlert = new TickTimer("My alert", "Description of my alert", 45);

	manager->addAlert(myAlert);
	manager->start();
    
    return application.exec();
}
