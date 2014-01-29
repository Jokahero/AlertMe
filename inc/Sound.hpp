#ifndef __SOUND_HPP__
#define __SOUND_HPP__

class QAudioOutput;

#include <QFile>

class Sound : public QObject{
public:
	Sound(const QString &label, const QString &path);
	~Sound();

	bool initialize();

public slots:
	void play();

private:
	QString			_label;
	QAudioOutput*	_output;
	QFile			_audioFile;
};

#endif // __SOUND_HPP__
