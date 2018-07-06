#include "BestTanks.h"

Bonus3::Bonus3(float const x, float const y) : Bonus(x, y) {
	_type = 1;
	_xyway.setX(x);
	_xyway.setY(y);
	_xyway.setWay(0);
}

//===================================================

int			Bonus3::bonusing(Player & player, vector<Tank *> & vecTank, vector<Texture *> & _vecTexture) {
	player.upScore(500);
	//////////KASKA
	return (0);
}

//===================================================

Bonus3::~Bonus3() {}
