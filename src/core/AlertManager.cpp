#include "core/AlertManager.hpp"

#include <iostream>

AlertManager::AlertManager() {}

AlertManager::~AlertManager() {
	for (QVector<AAlert*>::const_iterator it = _alerts.begin(); it != _alerts.end(); ++it)
		delete it;
}

void AlertManager::start() {
	std::cout << "[AlertManager] starting all timers" << std::endl;
	for (QVector<AAlert*>::const_iterator it = _alerts.begin(); it != _alerts.end(); ++it)
		startAlertTimer(*it);	
}

void AlertManager::startAlertTimer(AAlert* alert) {
	if (alert->isActive())
		alert->start();
	else
		std::cout << "[AlertManager] timer '" << alert->name().toStdString() << "' did not start because it is inactive" << std::endl;
}

