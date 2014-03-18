#include "core/features/Notification.hpp"

#include <QSystemTrayIcon>

//#include <QDebug>

namespace Feature {
	const QString Notification::NAME = "Notification";

	Notification::Notification(const QString& message) : _message(message) {}

	Notification::~Notification() {}

	void Notification::play() {
		if (_systemTrayIcon != NULL)
			_systemTrayIcon->showMessage("Alert !", _message);
		//qWarning << "Trying "
	}

	QString Notification::getName() const {
		return Notification::NAME;
	}
}
