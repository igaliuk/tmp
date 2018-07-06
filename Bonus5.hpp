#ifndef BONUS5_HPP
# define BONUS5_HPP

# include "BestTanks.h"

class Bonus5 : public Bonus {

	public:

		Bonus5(float const x, float const y);

		virtual int		bonusing(Player & player, vector<Tank *> & vecTank, vector<Texture *> & _vecTexture);

		virtual ~Bonus5();
};

#endif
