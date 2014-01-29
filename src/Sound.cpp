#include "Sound.hpp"

#include <QAudioFormat>
#include <QAudioOutput>

#include <iostream>

Sound::Sound(const QString &label, const QString &path) : _label(label) {
	_audioFile.setFileName(path);

}

Sound::~Sound() {
	delete _output;
}

void Sound::play() {
	if (_output)
		_output->start(&_audioFile);
	else
		std::cout << "Output file is NULL" << std::endl;
}

bool Sound::initialize() {
	if (QFile::exists(_audioFile.fileName()))
		_audioFile.open(QIODevice::ReadOnly);
	else {
		std::cout << "File does not exists" << std::endl;
		return false;
	}

	QAudioFormat format;
	//format.setFrequency(8000);
	//format.setChannels(1);
	format.setSampleSize(8);
	format.setCodec("audio/pcm");
	format.setByteOrder(QAudioFormat::LittleEndian);
	format.setSampleType(QAudioFormat::UnSignedInt);

	QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
	if (!info.isFormatSupported(format)) {
		std::cout << "[ERROR] raw audio format not supported by backend, cannot play audio." << std::endl;
		return false;
	}

	_output = new QAudioOutput(format);

	//connect(_output, SIGNAL(stateChanged(QAudio::State)), SLOT(finishedPlaying(QAudio::State)));

	return true;
}
