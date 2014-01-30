#ifndef __SOUND_HPP__
#define __SOUND_HPP__

class QAudioOutput;
class QSound;

#include <QObject>

class Sound : public QObject {
	Q_OBJECT

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
