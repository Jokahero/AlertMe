#include "core/AAlert.hpp"

#include "core/features/AFeature.hpp"

AAlert::AAlert(QString name, QString description) : _name(name), _description(description) {
	_active = true;
}

AAlert::~AAlert() {}

bool AAlert::addFeature(Feature::AFeature *feature) {
	if (feature == NULL)
		return false;

	if (hasFeature(feature->getName()))
		return false;

	_features.append(feature);
	return true;
}

bool AAlert::hasFeature(const QString &name) {
	for (Feature::AFeature* feature : _features)
		if (feature->getName() == name)
			return true;
	return false;
}

void AAlert::raise() {
	for (Feature::AFeature* feature : _features)
		feature->play();
}
