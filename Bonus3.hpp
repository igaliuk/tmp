#ifndef BONUS3_HPP
# define BONUS3_HPP

# include "BestTanks.h"

class Bonus3 : public Bonus {

	public:

		Bonus3(float const x, float const y);

		virtual int		bonusing(Player & player, vector<Tank *> & vecTank, vector<Texture *> & _vecTexture);

		virtual ~Bonus3();
};

#endif
