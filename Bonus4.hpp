#ifndef BONUS4_HPP
# define BONUS4_HPP

# include "BestTanks.h"

class Bonus4 : public Bonus {

	public:

		Bonus4(float const x, float const y);

		virtual int		bonusing(Player & player, vector<Tank *> & vecTank, vector<Texture *> & _vecTexture);

		virtual ~Bonus4();
};

#endif
