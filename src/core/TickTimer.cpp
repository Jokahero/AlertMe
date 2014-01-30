#include "core/TickTimer.hpp"

#include <QTimer>

#include <iostream>

TickTimer::TickTimer(const QString &name, const QString &description, unsigned int interval, QTime startTime) : AAlert(name, description), _interval(interval), _startTime(startTime) {
	_timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(raise()));

	_date = QDateTime(QDate::currentDate(), startTime, Qt::LocalTime);	
}

TickTimer::~TickTimer() {
	delete _timer;
}

void TickTimer::start() {
	std::cout << "[alert] " << _name.toStdString() << " : START (" << _date.time().toString().toStdString() << ")" << std::endl;
	if (QDate::currentDate() == _date.date())
		_timer->start(_interval * 1000);
}

void TickTimer::raise() {
	std::cout << "[alert] " << _name.toStdString() << " : RAISE (" << QTime::currentTime().toString().toStdString() << ")" <<  std::endl;
}

void TickTimer::setSound(Sound *sound) {
	AAlert::setSound(sound);
	if (_sound)
		connect(_timer, SIGNAL(timeout()), _sound, SLOT(play()));
}
