#ifndef __SOUND_HPP__
#define __SOUND_HPP__

#include "AFeature.hpp"

class QAudioOutput;
class QSound;

namespace Feature {
	class Sound : public AFeature {

	public:
		Sound(const QString &label, const QString &path);
		~Sound();

		bool initialize();

		virtual QString getName() const;

		virtual void play();

	private:
		QString			_label;
		QSound			*_sound;

		static const QString NAME;
	};
}
#endif // __SOUND_HPP__
