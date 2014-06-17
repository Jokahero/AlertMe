#ifndef __AALERT_HPP__
#define __AALERT_HPP__

namespace Feature {
	class AFeature;
}

#include <QDateTime>
#include <QObject>
#include <QVector>
#include <QString>

/**
 * \class AAlert
 *
 * \brief Abstract class for alerts
 */
class AAlert : public QObject {
	Q_OBJECT

    Q_PROPERTY(bool active MEMBER _active NOTIFY toggled)
    Q_PROPERTY(QString name MEMBER _name NOTIFY nameChanged)
    Q_PROPERTY(QString description MEMBER _description NOTIFY descriptionChanged)

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
	bool hasFeature(const QString &name);

	/**
	 * \brief Returns the list of features for this alert
	 *
	 * \return the feature list of the alert
	 */
	inline QVector<Feature::AFeature*> getFeatures() const;

protected:
	QString						_name;			///< \brief Name of the alert
	QString						_description;	///< \brief Description of the alert

	QDateTime					_date;			///< \brief Raising date
	
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
	virtual void stateChanged(bool state) = 0;

signals:
    void toggled(bool state);
    void nameChanged(QString name);
    void descriptionChanged(QString description);
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
    emit toggled(_active);
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
    emit nameChanged(_name);
}

inline void AAlert::setDescription(const QString &description) {
	_description = description;
    emit descriptionChanged(_description);
}

inline QVector<Feature::AFeature*> AAlert::getFeatures() const {
	return _features;
}

#endif // __AALERT_HPP__
