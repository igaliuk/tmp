#ifndef EAGLE_HPP
# define EAGLE_HPP

# include "BestTanks.h"

class Eagle : public Tank {

	private:

		int				_HP;
		XYWay			_xyway;
		int				_freeze;

	public:

		Eagle();

		virtual Bullet *		attack();

		virtual ~Eagle();
};

#endif
