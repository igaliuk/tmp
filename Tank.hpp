#ifndef TANK_HPP
# define TANK_HPP

# include "BestTanks.h"

class Bullet;

class Tank {

	private:

		int				_type;
        int             _respTime;
		int				_HP;
		int				_ammo;
		float			_speed;
		XYWay			_xyway;
		int				_freeze;
		Bullet			*_bullet;
		Bullet			*_bullet2;

	public:

		Tank();

		int						getType() const;
        int                     getRespTime() const;
		int						getHP() const;
		int						getAmmo() const;
		float					getSpeed() const;
		XYWay &					getXYWay();
		int						getFreeze();

		void					setHP(int const HP);
		void					setAmmo(int const  ammo);
		void					setSpeed(float const speed);

		virtual Bullet *		attack() = 0;
		void					changeFreeze();
		void					turn(int const way);
		void					move(int const way);
		void					reload();
		_Bool					takeDamage();

		virtual ~Tank();
};

#endif
