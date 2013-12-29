#ifndef __TICK_TIMER_HPP__
#define __TICK_TIMER_HPP__

#include "AAlert.hpp"

class QTimer;

class TickTimer : public AAlert {
	Q_OBJECT

	public:
		TickTimer(const QString &name, const QString &description, unsigned int interval, QTime startTime = QTime::currentTime());
		virtual ~TickTimer();

	virtual void start();

	public slots:
		virtual void raise();

	protected:
		unsigned int	_interval;
		QTime			_startTime;

	private:
		QTimer*			_timer;
};

#endif // __TICK_TIMER_HPP__
