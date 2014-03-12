#ifndef __TICK_TIMER_HPP__
#define __TICK_TIMER_HPP__

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

	public slots:
	virtual void raise();

protected:
	unsigned int	_interval;		///< \brief Interval between two ticks
	QTime			_startTime;		///< \brief First tick time

private:
	QTimer*			_timer;
};

#endif // __TICK_TIMER_HPP__
