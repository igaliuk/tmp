#include "BestTanks.h"

Eagle::Eagle() {
	_type = EAGLE;
	_resp = 0;
	_HP = 1;
	_speed = 0;
	_xyway.setX(START_POS_X_EA);
	_xyway.setY(START_POS_Y_EA);
	_xyway.setWay(0);
	_freeze = 0;
	_bullet = NULL;
	_bullet2 = NULL;
}

//===================================================

Bullet *	Eagle::attack() {
	return (NULL);
}

//===================================================

Eagle::~Eagle() {}
