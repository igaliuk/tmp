#ifndef TANK_HPP
# define TANK_HPP

# include "BestTanks.h"

class Bullet;

class Tank {

	private:

		int				_type;
		int				_HP;
		int				_ammo;
		float			_speed;
		XYWay			_xyway;
		Bullet			*_bullet;

	public:

		Tank();

		int						getType() const;
		int						getHP() const;
		int						getAmmo() const;
		float					getSpeed() const;
		XYWay					&getXYWay();

		void					setHP(int const HP);
		void					setAmmo(int const  ammo);
		void					setSpeed(float const speed);

		Bullet *				attack();
		void					move(int const way);
		void					reload();
		_Bool					takeDamage();

		virtual ~Tank();
};

#endif
