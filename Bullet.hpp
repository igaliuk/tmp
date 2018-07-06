#ifndef BULLET_HPP
# define BULLET_HPP

# include "BestTanks.h"

class Bullet {

	private:

		int				_power;
		float			_speed;
		XYWay			_xyway;
		_Bool			_status;
		Tank &			_tank;

	public:

		Bullet(float const speed, _Bool const status, Tank & tank);

		int				getPower() const;
		float			getSpeed() const;
		XYWay &			getXYWay();
		_Bool			getStatus() const;
		Tank &			getTank();

		void			setPower(int const power);
		void			setSpeed(float const speed);
		void			setXYWay(XYWay const & xyway);

		void			changeStatus();
		void			move();

		~Bullet();
};

#endif
