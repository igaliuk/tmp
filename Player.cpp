#include "BestTanks.h"

Player::Player() {}

Player::Player(int const type, int const x, int const y) {
	_type = type;
	_rank = 0;
	_HP = 1;
	_lifes = 3;
	_score = 0;
	_ammo = 1;
	_speed = 0;
	_xyway.setX(x);
	_xyway.setY(y);
	_xyway.setWay(UP);
	_bullet = new Bullet(SPEED_BULLET1);
}

//===================================================

int			Player::getRank() const {
	return (_rank);
}

int			Player::getLifes() const {
	return (_lifes);
}

int			Player::getScore() const {
	return (_score);
}

//===================================================

void		Player::setRank(int const rank) {
	_rank = rank;
}

void		Player::setLifes(int const lifes) {
	_lifes = lifes;
}

void		Player::setScore(int const score) {
	_score = score;
}

//===================================================

Player::~Player() {}

//if (type == 1) {
//_xyway.setX(START_POS_X_PL1);
//_xyway.setY(START_POS_Y_PL1);
//}
//else {
//_xyway.setX(START_POS_X_PL2);
//_xyway.setY(START_POS_Y_PL2);
//}