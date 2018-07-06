#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "BestTanks.h"

class Enemy : public Tank {

	private:

	public:

		Enemy(int const type, int const HP, float const tspeed, float const x, float const y, float bspeed);

		virtual Bullet *		attack();

		virtual ~Enemy();
};

#endif
