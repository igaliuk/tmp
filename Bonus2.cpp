#include "BestTanks.h"

Bonus2::Bonus2(float const x, float const y) : Bonus(x, y) {
	_type = 1;
	_xyway.setX(x);
	_xyway.setY(y);
	_xyway.setWay(0);
}

//===================================================

int			Bonus2::bonusing(Player & player, vector<Tank *> & vecTank, vector<Texture *> & _vecTexture) {
	player.upScore(500);
	player.upRank();
	return (0);
}

//===================================================

Bonus2::~Bonus2() {}
