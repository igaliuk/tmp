#ifndef TANK_HPP
# define TANK_HPP

# include "BestTanks.h"

class Bullet;

class Tank {

	protected:

		int				_type;
		int				_resp;
		int				_HP;
		float			_speed;
		XYWay			_xyway;
		int				_freeze;
		Bullet			*_bullet;
		Bullet			*_bullet2;

	public:

		Tank();

		int						getType() const;
		int						getResp() const;
		int						getHP() const;
		float					getSpeed() const;
		XYWay &					getXYWay();
		int						getFreeze() const;

		void					setType(int const type);
		void					setHP(int const HP);
		void					setSpeed(float const speed);
		void					setFreeze(int const freeze);

		virtual Bullet *		attack() = 0;
		void					changeFreeze();
		void					turn(int const way);
		void					move(int const way, string const mapOfPassability);
		_Bool					takeDamage();

		virtual ~Tank();
};

#endif
