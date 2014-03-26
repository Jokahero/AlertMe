#ifndef __NOTIFICATION_HPP__
#define __NOTIFICATION_HPP__

#include "AFeature.hpp"

class QSystemTrayIcon;

namespace Feature {
	/**
	 * \class Notification
	 * \brief Notification feature 
	 * 
	 * A feature that shows a notification out of the system tray icon on tick
	 */
	class Notification : public AFeature {
	public:
		/**
		 * \brief Constructor
		 *
		 * \param message	Message to fill the notification with
		 */
		Notification(const QString& message);
		/**
		 * \brief Destructor
		 */
		~Notification();

		virtual void play();

		virtual QString getName() const;

		/**
		 * \brief Sets the system tray icon to use to show the notification
		 *
		 * \param systemTrayIcon	System tray icon reference
		 */
		inline void setSystemTrayIcon(QSystemTrayIcon* systemTrayIcon);

	private:
		QString				_message;			///< \brief Message to show with the notification

		QSystemTrayIcon*	_systemTrayIcon;	///< \brief System tray icon to show the notification

		static const QString NAME;				///< \brief Feature's name
	};

	inline void Notification::setSystemTrayIcon(QSystemTrayIcon *systemTrayIcon) {
		_systemTrayIcon = systemTrayIcon;
	}
}

#endif // __NOTIFICATION_HPP__
