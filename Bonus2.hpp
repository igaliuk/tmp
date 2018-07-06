#ifndef BONUS2_HPP
# define BONUS2_HPP

# include "BestTanks.h"

class Bonus2 : public Bonus {

	public:

		Bonus2(float const x, float const y);

		virtual int		bonusing(Player & player, vector<Tank *> & vecTank, vector<Texture *> & _vecTexture);

		virtual ~Bonus2();
};

#endif
