#include "inc/AlertManager.hpp"

AlertManager::AlertManager() {}

AlertManager::~AlertManager() {
	for (QVector<AAlert*>::const_iterator it = _alerts.begin(); it != _alerts.end(); ++it)
		delete it;
}

void AlertManager::start() {
	for (QVector<AAlert*>::const_iterator it = _alerts.begin(); it != _alerts.end(); ++it)
		startAlertTimer(*it);	
}

void AlertManager::startAlertTimer(AAlert* alert) {
	if (alert->isActive())
		alert->start();
}

