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
		Bullet			*_bullet;

	public:

		Enemy();
		Enemy(int const type, float const tspeed,int const x, int const y, float bspeed);

		virtual ~Enemy();
};

#endif