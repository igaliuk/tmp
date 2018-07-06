#include "BestTanks.h"

Bonus5::Bonus5(float const x, float const y) : Bonus(x, y) {
	_type = 1;
	_xyway.setX(x);
	_xyway.setY(y);
	_xyway.setWay(0);
}

//===================================================

int			Bonus5::bonusing(Player & player, vector<Tank *> & vecTank, vector<Texture *> & _vecTexture) {
	player.upScore(500);
	return (FREEZE_TIME);
}

//===================================================

Bonus5::~Bonus5() {}
