#ifndef XYWAY_HPP
# define XYWAY_HPP

# include "BestTanks.h"

class XYWay {

	private:

		float			_x;
		float			_y;
		int				_way;

	public:

		float			getX() const;
		float			getY() const;
		int				getWay() const;

		void			setX(float const x);
		void			setY(float const y);
		void			setWay(int const way);
};
#endif