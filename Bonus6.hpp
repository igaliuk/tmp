#ifndef BONUS6_HPP
# define BONUS6_HPP

# include "BestTanks.h"

class Bonus6 : public Bonus {

	public:

		Bonus6(float const x, float const y);

		virtual int		bonusing(Player & player, vector<Tank *> & vecTank, vector<Texture *> & _vecTexture);

		virtual ~Bonus6();
};

#endif
