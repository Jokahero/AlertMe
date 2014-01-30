#include "core/AAlert.hpp"

AAlert::AAlert(QString name, QString description) : _name(name), _description(description) {
	_active = true;
}

AAlert::~AAlert() {}
