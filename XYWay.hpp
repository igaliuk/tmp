#ifndef XYWAY_HPP
# define XYWAY_HPP

# include "BestTanks.h"

class XYWay {

	private:

		float			_x;
		float			_y;
		int				_way;

	public:

		XYWay();
		XYWay(float const x, float const y);

		XYWay &			operator = (XYWay const & obj);
		_Bool			operator == (XYWay const & obj);

		float			getX() const;
		float			getY() const;
		int				getWay() const;
		int				getXRound() const;
		int				getYRound() const;

		void			setX(float const x);
		void			setY(float const y);
		void			setWay(int const way);

		void			smartShift();
		int				getXRoundWithShift(float const shift) const;
		int				getYRoundWithShift(float const shift) const;

		~XYWay();
};
#endif