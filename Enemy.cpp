#include "BestTanks.h"

Enemy::Enemy() {}

Enemy::Enemy(int const type, float const tspeed,int const x, int const y, float bspeed) {
	_type = type;
	_HP = 1;
	_ammo = 1;
	_speed = tspeed;
	_xyway.setX(x);
	_xyway.setY(y);
	_xyway.setWay(DOWN);
	_bullet = new Bullet(bspeed);
}

//===================================================

Enemy::~Enemy() {}

//static int		position = 1;
//if (position == 1) {
//_xyway.setX(START_POS_X_EN1);
//_xyway.setY(START_POS_Y_EN1);
//}
//else if (position == 2) {
//_xyway.setX(START_POS_X_EN2);
//_xyway.setY(START_POS_Y_EN2);
//}
//else {
//_xyway.setX(START_POS_X_EN3);
//_xyway.setY(START_POS_Y_EN3);
//}
//if (++position > 3)
//position = 1;
//if (type == 5)
//_bullet = new Bullet(SPEED_BULLET2);
//else
//_bullet = new Bullet(SPEED_BULLET1);