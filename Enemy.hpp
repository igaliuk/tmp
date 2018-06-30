#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "BestTanks.h"

class Enemy : public Tank {

	private:

		int				_type;
		int				_HP;
		int				_ammo;
		float			_speed;
		XYWay			_xyway;
		int				_freeze;
		Bullet			*_bullet;

	public:

		Enemy();
		Enemy(int const type, float const tspeed, float const x, float const y, float bspeed);

		virtual Bullet *		attack();

		virtual ~Enemy();
};

#endif
