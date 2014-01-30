#ifndef __SOUND_HPP__
#define __SOUND_HPP__

class QAudioOutput;
class QSound;

#include <QFile>

class Sound : public QObject {
public:
	Sound(const QString &label, const QString &path);
	~Sound();

	bool initialize();

public slots:
	void play();

private:
	QString			_label;
	QSound			*_sound;
};

#endif // __SOUND_HPP__
