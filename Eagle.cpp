#include "BestTanks.h"

Eagle::Eagle() {
	_HP = 1;
	_xyway.setX(START_POS_X_EA);
	_xyway.setY(START_POS_Y_EA);
	_xyway.setWay(0);
	_freeze = 0;
}

//===================================================

Bullet *	Eagle::attack() {
	return (NULL);
}

//===================================================

Eagle::~Eagle() {}