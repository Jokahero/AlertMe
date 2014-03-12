#ifndef __SOUND_HPP__
#define __SOUND_HPP__

#include "AFeature.hpp"

class QAudioOutput;
class QSound;

namespace Feature {
	/**
	 * \class Sound
	 * \brief Sound feature
	 * 
	 * A feature tha allows alarm to play a sound on tick
	 */
	class Sound : public AFeature {

	public:
		/**
		 * \brief Constructor
		 *
		 * \param label	Sound label
		 * \param path	Sound path
		 */
		Sound(const QString &label, const QString &path);
		
		/**
		 * \brief Destructor
		 */
		~Sound();

		bool initialize();

		virtual QString getName() const;

		virtual void play();

	private:
		QString			_label;		///< \brief Sound's label
		QSound			*_sound;	///< \brief Sound to be played

		static const QString NAME;		///< \brief Feature's name
	};
}
#endif // __SOUND_HPP__
