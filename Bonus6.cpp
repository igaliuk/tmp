#include "BestTanks.h"

Bonus6::Bonus6(float const x, float const y) : Bonus(x, y) {
	_type = 1;
	_xyway.setX(x);
	_xyway.setY(y);
	_xyway.setWay(0);
}

//===================================================

int			Bonus6::bonusing(Player & player, vector<Tank *> & vecTank, vector<Texture *> & _vecTexture) {
	player.upScore(500);
	while (vecTank.size() > 3) {
		delete vecTank[3];
		vecTank.erase(vecTank.begin() + 3);
	}
	return (0);
}

//===================================================

Bonus6::~Bonus6() {}
