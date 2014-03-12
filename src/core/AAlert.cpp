#include "core/AAlert.hpp"

AAlert::AAlert(QString name, QString description) : _name(name), _description(description) {
	_active = true;
	_sound = NULL;
}

AAlert::~AAlert() {}

void AAlert::setSound(Feature::Sound *sound) {
	_sound = sound;
}

