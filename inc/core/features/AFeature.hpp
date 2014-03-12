#ifndef __AFEATURE_HPP__
#define __AFEATURE_HPP__

#include <QString>

namespace Feature {
	/**
	 * \class AFeature
	 * \brief Feature abstract class
	 *
	 * A feature describes a behaviour that can be processed on an alert tick
	 */
	class AFeature {
	public:
		/**
		 * \brief Returns the feature's name
		 *
		 * \return the name of the feature
		 */
		virtual QString getName() const = 0;

		/**
		 * \brief Plays the feature
		 *
		 * Process the feature's specific behaviour
		 */
		virtual void play() = 0;
	};
}
#endif // __AFEATURE_HPP__
