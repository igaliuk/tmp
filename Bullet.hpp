#ifndef BULLET_HPP
# define BULLET_HPP

# include "BestTanks.h"

class Bullet {

	private:

		int				_power;
		float			_speed;
		XYWay			_xyway;
		_Bool			_status;

	public:

		Bullet(float const speed);

		int				getPower() const;
		float			getSpeed() const;
		XYWay &			getXYWay();
		_Bool			getStatus();

    void           setPower(int const power);
    void        setSpeed(float const speed);
		void			setXYWay(XYWay const & xyway);

		void			changeStatus();
		void			move();

		~Bullet();
};

#endif
