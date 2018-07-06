#include "BestTanks.h"

Bonus1::Bonus1(float const x, float const y) : Bonus(x, y) {
	_type = 1;
	_xyway.setX(x);
	_xyway.setY(y);
	_xyway.setWay(0);
}

//===================================================

int			Bonus1::bonusing(Player & player, vector<Tank *> & vecTank, vector<Texture *> & _vecTexture) {
	player.upScore(500);
	player.setLifes(player.getLifes() + 1);
	return (0);
}

//===================================================

Bonus1::~Bonus1() {}
