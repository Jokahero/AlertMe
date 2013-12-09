#ifndef __AALERT_HPP__
#define __AALERT_HPP__

#include <QString>

/**
 * \class AAlert
 *
 * \brief Abstract class for alerts
 */
class AAlert {
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
	virtual ~AAlert() = 0;

	/**
	 * \brief It is time !
	 */
	virtual void raise() = 0;

protected:
	QString		_name;			///< \brief Name of the alert
	QString		_description;	///< \brief Description of the alert
};

#endif // __AALERT_HPP__
