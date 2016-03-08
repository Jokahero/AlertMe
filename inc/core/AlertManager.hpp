#ifndef ALERT_MANAGER_HPP
#define ALERT_MANAGER_HPP

class Alert;

#include <QVector>

#include <QtQml/qqmllist.h>

/**
 * \class AlertManager
 * \brief Manages alerts
 * 
 * Manages a list of alerts
 */
class AlertManager {
public:
    /**
	 * \brief Constructor
	 */
	AlertManager();
	
    /**
	 * \brief Destructor
	 */
	virtual ~AlertManager();

    /**
	 * \brief Adds an alert in the list
	 *
	 * \param alert Alert to add
	 */
    inline void addAlert(Alert* alert);

    /**
	 * \brief Starts the alerts
	 *
	 * Starts all active alerts
	 */
	void start();

    inline QVector<Alert*> getAlerts();

private:
    QVector<Alert*>	_alerts;		///< \brief List of alerts

	void startAlertTimer(Alert* alert);
};

inline void AlertManager::addAlert(Alert* alert) {
	_alerts.push_back(alert);
}

inline QVector<Alert*> AlertManager::getAlerts() {
    return _alerts;
}

#endif // ALERT_MANAGER_HPP
