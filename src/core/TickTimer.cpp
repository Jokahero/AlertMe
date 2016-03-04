#include "core/TickTimer.hpp"

#include <QTimer>

#include <iostream>

const QString TickTimer::DEFAULT_NAME = "New alert";
const QString TickTimer::DEFAULT_DESCRIPTION = "New alert's description";
const unsigned int TickTimer::DEFAULT_INTERVAL = 300;

TickTimer::TickTimer() : TickTimer(DEFAULT_NAME, DEFAULT_DESCRIPTION, DEFAULT_INTERVAL) {}

TickTimer::TickTimer(const QString &name, const QString &description, unsigned int interval, QTime startTime) : AAlert(name, description), _interval(interval), _startTime(startTime) {
	_timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(raise()));

	_date = QDateTime(QDate::currentDate(), startTime, Qt::LocalTime);	

	connect(this, &AAlert::toggled, this, &TickTimer::stateChanged);
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
	AAlert::raise();
	std::cout << "[alert] " << _name.toStdString() << " : RAISE (" << QTime::currentTime().toString().toStdString() << ")" <<  std::endl;
}

void TickTimer::stateChanged(bool state) {
	state ? start() : _timer->stop();
}

bool TickTimer::isDefault() const {
	return _name == DEFAULT_NAME && _description == DEFAULT_DESCRIPTION && _interval == DEFAULT_INTERVAL;
}
