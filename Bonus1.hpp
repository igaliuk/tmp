#ifndef BONUS1_HPP
# define BONUS1_HPP

# include "BestTanks.h"

class Bonus1 : public Bonus {

	public:

		Bonus1(float const x, float const y);

		virtual int		bonusing(Player & player, vector<Tank *> & vecTank, vector<Texture *> & _vecTexture) = 0;

		virtual ~Bonus1();
};

#endif
