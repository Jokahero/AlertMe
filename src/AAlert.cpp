#include "inc/AAlert.hpp"

AAlert::AAlert(QString name, QString description) : _name(name), _description(description) {
	_active = true;
}

AAlert::~AAlert() {}

void AAlert::setSound(Sound *sound) {
	_sound = sound;
}

