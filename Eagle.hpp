#ifndef EAGLE_HPP
# define EAGLE_HPP

# include "BestTanks.h"

class Eagle : public Tank {

	private:

	public:

		Eagle();

		virtual Bullet *		attack();

		virtual ~Eagle();
};

#endif
