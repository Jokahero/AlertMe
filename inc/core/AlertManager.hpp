#ifndef __ALERT_MANAGER_HPP__
#define __ALERT_MANAGER_HPP__

#include "AAlert.hpp"

#include <QVector>

class AlertManager {
public:
	AlertManager();
	virtual ~AlertManager();

	inline void addAlert(AAlert* alert);

	void start();

private:
	QVector<AAlert*>	_alerts;

	void startAlertTimer(AAlert* alert);
};

inline void AlertManager::addAlert(AAlert* alert) {
	_alerts.push_back(alert);
}

#endif // __ALERT_MANAGER_HPP__
