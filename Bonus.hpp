#ifndef BONUS_HPP
# define BONUS_HPP

# include "BestTanks.h"

class Bonus {

	protected:

		int				_type;
		XYWay			_xyway;

	public:

		Bonus(float const x, float const y);

		int				getType() const;
		XYWay &			getXYWay();

		virtual int		bonusing(Player & player, vector<Tank *> & vecTank, vector<Texture *> & _vecTexture) = 0;

		virtual ~Bonus();
};

#endif
