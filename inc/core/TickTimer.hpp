#ifndef TICK_TIMER_HPP
#define TICK_TIMER_HPP

#include "AAlert.hpp"

class QTimer;

/**
 * \class TickTimer
 *
 * \brief Basic timer raising at regular interval
 */
class TickTimer : public AAlert {
	Q_OBJECT

public:
	/**
	 * @brief Default constructor
	 */
	TickTimer();

	/**
	 * \brief Constructor
	 *
	 * \param name			Timer's name
	 * \param description	Timer's description
	 * \param interval		Interval between two tick (in seconds)
	 * \param startTime		First tick time
	 */
	TickTimer(const QString &name, const QString &description, unsigned int interval, QTime startTime = QTime::currentTime());

	/**
	 * \brief Destructor
	 */
	virtual ~TickTimer();

	virtual void start();

	virtual bool isDefault() const override;

public slots:
    virtual void raise();

	virtual void stateChanged(bool state);

protected:
	unsigned int	_interval;		///< \brief Interval between two ticks
	QTime			_startTime;		///< \brief First tick time

private:
	QTimer*			_timer;

	static const QString DEFAULT_NAME;
	static const QString DEFAULT_DESCRIPTION;
	static const unsigned int DEFAULT_INTERVAL;
};

#endif // TICK_TIMER_HPP
