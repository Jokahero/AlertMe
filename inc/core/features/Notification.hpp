#ifndef __NOTIFICATION_HPP__
#define __NOTIFICATION_HPP__

#include "AFeature.hpp"

class QSystemTrayIcon;

namespace Feature {
	class Notification : public AFeature {
	public:
		Notification(const QString& message);
		~Notification();

		virtual void play();

		virtual QString getName() const;

		inline void setSystemTrayIcon(QSystemTrayIcon* systemTrayIcon);

	private:
		QString				_message;

		QSystemTrayIcon*	_systemTrayIcon;

		static const QString NAME;
	};

	inline void Notification::setSystemTrayIcon(QSystemTrayIcon *systemTrayIcon) {
		_systemTrayIcon = systemTrayIcon;
	}
}

#endif // __NOTIFICATION_HPP__
