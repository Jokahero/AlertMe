#ifndef __AALERT_HPP__
#define __AALERT_HPP__

#include <QDateTime>
#include <QObject>
#include <QString>

/**
 * \class AAlert
 *
 * \brief Abstract class for alerts
 */
class AAlert : public QObject {
	Q_OBJECT

public:
	/**
	 * \brief Constructor
	 *
	 * \param name			Alert name
	 * \param description	Description name
	 */
    AAlert(QString name, QString description);

	/**
	 * \brief Destructor
	 */
	virtual ~AAlert();

	/**
	 * \brief Starts the alert's timer
	 */
	virtual void start() = 0;

	/**
	 * \brief Sets the raising date of this alert
	 *
	 * \param date	Date
	 */
	inline void setDate(QDateTime date);

	/**
	 * \brief Returns the raising date of this alert
	 *
	 * \return the raising date
	 */
	inline QDateTime getDate();

	/**
	 * \brief Sets whether the alert is repetitive or not
	 *
	 * \param repetitive repetitive state for this alert
	 */
	inline void setRepetitive(bool repetitive);

	/**
	 * \brief Returns the repetitive state of this alert
	 *
	 * \return true if the alert is repetitive, false otherwise
	 */
	inline bool isRepetitive();
	
	/**
	 * \brief Sets whether this alert is active or not
	 *
	 * \param active active state for this alert
	 */
	inline void setActive(bool active);

	/**
	 * \brief Returns the active state of this alert
	 *
	 * \return true if the alert is active, false otherwise 
	 */
	inline bool isActive();

	/**
	 * \brief Returns the name of the alert
	 *
	 * \return the name of the alert
	 */
	inline QString name() const;

	/**
	 * \brief Returns the description of the alert
	 *
	 * \return the description of the alert
	 */
	inline QString description() const;

	/**
	 * \brief Sets the name of the alert
	 */
	inline void setName(const QString &name);

	/**
	 * \brief Sets the description of the alert
	 */
	inline void setDescription(const QString &description);

protected:
	QString			_name;			///< \brief Name of the alert
	QString			_description;	///< \brief Description of the alert

	QDateTime		_date;			///< \brief Raising date
	
	bool 			_active;		///< \brief Is the alert active
	bool			_repetitive;	///< \brief Is the alert repetitive

public slots:
	/**
	 * \brief It is time !
	 */
	virtual void raise() = 0;
};

inline void AAlert::setDate(QDateTime date) {
	_date = date;
}

inline QDateTime AAlert::getDate() {
	return _date;
}

inline void AAlert::setRepetitive(bool repetitive) {
	_repetitive = repetitive;
}

inline bool AAlert::isRepetitive() {
	return _repetitive;
}

inline void AAlert::setActive(bool active) {
	_active = active;
}

inline bool AAlert::isActive() {
	return _active;
}

inline QString AAlert::name() const {
	return _name;
}

inline QString AAlert::description() const {
	return _description;
}

inline void AAlert::setName(const QString &name) {
	_name = name;
}

inline void AAlert::setDescription(const QString &description) {
	_description = description;
}

#endif // __AALERT_HPP__
