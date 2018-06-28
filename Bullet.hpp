#ifndef BULLET_HPP
# define BULLET_HPP

# include "BestTanks.h"

class ITank;

class Bullet {

	private:

		int				_power;
		float			_speed;
		XYWay			_xyway;

	public:

		Bullet(float const speed);

		int				getPower() const;
		float			getSpeed() const;
		XYWay			&getXYWay();

		void			move(int const way);

		~Bullet();
};

#endif