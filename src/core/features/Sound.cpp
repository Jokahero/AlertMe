#include "core/features/Sound.hpp"

#include <QSound>

#include <iostream>
namespace Feature {
	const QString Sound::NAME = "Sound";

	Sound::Sound(const QString &label, const QString &path) : _label(label) {
		_sound = new QSound(path);
	}

	Sound::~Sound() {
		delete _sound;
	}

	QString Sound::getName() const {
		return Sound::NAME;
	}

	void Sound::play() {
		if (_sound)
			_sound->play();
		else
			std::cerr << "Cannot play sound '" << _label.toStdString() << "' because it is NULL"  << std::endl;
	}
}
