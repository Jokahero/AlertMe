#include "core/Alert.hpp"

#include "core/features/AFeature.hpp"

#include <QTimer>

#include <iostream>

const QString Alert::DEFAULT_NAME = "New alert";
const QString Alert::DEFAULT_DESCRIPTION = "New alert's description";
const unsigned int Alert::DEFAULT_INTERVAL = 300;

Alert::Alert(QObject *parent) : QObject(parent), _name(DEFAULT_NAME), _description(DEFAULT_DESCRIPTION), _delay(DEFAULT_INTERVAL) {
	_date = QDateTime::currentDateTime();
	_active = false;
	_repetitive = false;

	_timer = new QTimer(this);
	connect(_timer, SIGNAL(timeout()), this, SLOT(raise()));
}

Alert::Alert(const QString &name, const QString &description, unsigned int delay, QDateTime startDate, QObject *parent) : QObject(parent),  _name(name), _description(description), _date(startDate), _delay(delay) {
	_active = true;
	_repetitive = false;

	//  TODO use the startTimer feature of QObject
	_timer = new QTimer(this);
	connect(_timer, SIGNAL(timeout()), this, SLOT(raise()));
}

Alert::~Alert() {
	delete _timer;
}

bool Alert::addFeature(Feature::AFeature *feature) {
	if (feature == NULL)
		return false;

	if (hasFeature(feature->getName()))
		return false;

	_features.append(feature);
	return true;
}

void Alert::start() {
	std::cout << "[alert] " << _name.toStdString() << " : START (" << _date.time().toString().toStdString() << ")" << std::endl;
	//  TODO use the startTimer feature of QObject
	if (QDate::currentDate() == _date.date())
		_timer->start(_delay * 1000);
}

bool Alert::hasFeature(const QString &name) const {
	// TODO use std::find_if
	for (Feature::AFeature* feature : _features)
		if (feature->getName() == name)
			return true;
	return false;
}

void Alert::raise() {
	std::cout << "[alert] " << _name.toStdString() << " : RAISE (" << QTime::currentTime().toString().toStdString() << ")" <<  std::endl;
	for (Feature::AFeature* feature : _features)
		feature->play();
}

void Alert::stateChanged(bool state) {
	state ? start() : _timer->stop();
}

bool Alert::isDefault() const {
	return _name == DEFAULT_NAME && _description == DEFAULT_DESCRIPTION && _delay == DEFAULT_INTERVAL;
}
