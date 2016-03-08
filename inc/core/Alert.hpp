#ifndef A_ALERT_HPP
#define A_ALERT_HPP

namespace Feature {
	class AFeature;
}

class QTimer;

#include <QDateTime>
#include <QObject>
#include <QVector>
#include <QString>

/**
 * \class AAlert
 *
 * \brief Abstract class for alerts
 */
class Alert : public QObject {
	Q_OBJECT

public:
	/**
	 * @brief Default constructor
	 */
	Alert(QObject *parent = nullptr);

	/**
	 * \brief Constructor
	 *
	 * \param name			Alert name
	 * \param description	Description name
	 */
	Alert(const QString &name, const QString &description, unsigned int delay, QDateTime startDate = QDateTime::currentDateTime(), QObject *parent = nullptr);

	/**
	 * \brief Destructor
	 */
	virtual ~Alert();

	/**
	 * \brief Starts the alert's timer
	 */
	virtual void start();

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
	inline const QDateTime& getDate() const;

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
	inline bool isRepetitive() const;

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
	inline bool isActive() const;

	/**
	 * \brief Returns the name of the alert
	 *
	 * \return the name of the alert
	 */
	inline const QString& name() const;

	/**
	 * \brief Returns the description of the alert
	 *
	 * \return the description of the alert
	 */
	inline const QString& description() const;

	/**
	 * \brief Sets the name of the alert
	 */
	inline void setName(const QString &name);

	/**
	 * \brief Sets the description of the alert
	 */
	inline void setDescription(const QString &description);

	/**
	 * \brief Add a feature to the alert
	 *
	 * \param feature Feature to add
	 *
	 * \return true if the feature has been correctly added, false otherwise
	 */
	bool addFeature(Feature::AFeature *feature);

	/**
	 * \brief Asks the alarmert if it has a feature
	 *
	 * \param name	Feature name
	 *
	 * \return true if the alarm has the feature, false otherwise
	 */
	bool hasFeature(const QString &name) const;

	/**
	 * \brief Returns the list of features for this alert
	 *
	 * \return the feature list of the alert
	 */
	inline QVector<Feature::AFeature*> getFeatures() const;

	/**
	 * @brief Returns whether this alert is filled with default values
	 *
	 * @return true if it is a default-constructed object, false otherwise
	 */
	virtual bool isDefault() const;

protected:
	QString						_name;			///< \brief Name of the alert
	QString						_description;	///< \brief Description of the alert

	QDateTime					_date;			///< \brief First tick
	unsigned int				_delay;			///< \brief Interval between two ticks

	bool						_active;		///< \brief Is the alert active
	bool						_repetitive;	///< \brief Is the alert repetitive

	QVector<Feature::AFeature*>	_features;		///< \brief List of features for this alert

public slots:
	/**
	 * \brief It is time !
	 */
	virtual void raise();

	/**
	 * \brief User has switch the alert's state
	 *
	 * \param state New alert's state
	 */
	virtual void stateChanged(bool state);

private:
	QTimer*			_timer;

	static const QString DEFAULT_NAME;
	static const QString DEFAULT_DESCRIPTION;
	static const unsigned int DEFAULT_INTERVAL;
};

inline void Alert::setDate(QDateTime date) {
	_date = date;
}

inline const QDateTime& Alert::getDate() const {
	return _date;
}

inline void Alert::setRepetitive(bool repetitive) {
	_repetitive = repetitive;
}

inline bool Alert::isRepetitive() const {
	return _repetitive;
}

inline void Alert::setActive(bool active) {
	_active = active;
}

inline bool Alert::isActive() const {
	return _active;
}

inline const QString& Alert::name() const {
	return _name;
}

inline const QString& Alert::description() const {
	return _description;
}

inline void Alert::setName(const QString &name) {
	_name = name;
}

inline void Alert::setDescription(const QString &description) {
	_description = description;
}

inline QVector<Feature::AFeature*> Alert::getFeatures() const {
	return _features;
}

#endif // A_ALERT_HPP
