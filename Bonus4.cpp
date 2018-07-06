#include "BestTanks.h"

Bonus4::Bonus4(float const x, float const y) : Bonus(x, y) {
	_type = 1;
	_xyway.setX(x);
	_xyway.setY(y);
	_xyway.setWay(0);
}

//===================================================

int			Bonus4::bonusing(Player & player, vector<Tank *> & vecTank, vector<Texture *> & _vecTexture) {
	player.upScore(500);
	_vecTexture.push_back(new Texture(2, 2, 0, 0, 0.0, START_POS_Y_EA - 1.0f, START_POS_X_EA - 1.0f));
	_vecTexture.push_back(new Texture(2, 2, 0, 0, 0.0, START_POS_Y_EA - 1.0f, START_POS_X_EA));
	_vecTexture.push_back(new Texture(2, 2, 0, 0, 0.0, START_POS_Y_EA - 1.0f, START_POS_X_EA + 1.0f));
	_vecTexture.push_back(new Texture(2, 2, 0, 0, 0.0, START_POS_Y_EA, START_POS_X_EA - 1.0f));
	_vecTexture.push_back(new Texture(2, 2, 0, 0, 0.0, START_POS_Y_EA, START_POS_X_EA + 1.0f));
	return (0);
}

//===================================================

Bonus4::~Bonus4() {}
