#include "core/AlertManager.hpp"

#include "core/Alert.hpp"

#include <iostream>

AlertManager::AlertManager() {}

AlertManager::~AlertManager() {
	for (Alert* alert : _alerts)
		delete alert;
}

void AlertManager::start() {
	std::cout << "[AlertManager] starting all timers" << std::endl;
	for (QVector<Alert*>::const_iterator it = _alerts.begin(); it != _alerts.end(); ++it)
		startAlertTimer(*it);
}

void AlertManager::startAlertTimer(Alert* alert) {
	if (alert->isActive())
		alert->start();
	else
		std::cout << "[AlertManager] timer '" << alert->name().toStdString() << "' did not start because it is inactive" << std::endl;
}
