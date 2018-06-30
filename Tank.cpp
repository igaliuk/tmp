#include "BestTanks.h"

Tank::Tank() {}

//===================================================

int			Tank::getType() const {
	return (_type);
}

int			Tank::getHP() const {
	return (_HP);
}

int			Tank::getAmmo() const {
	return (_ammo);
}

float		Tank::getSpeed() const {
	return (_speed);
}

XYWay		&Tank::getXYWay() {
	return (_xyway);
}

int			Tank::getFreeze() {
	return (_freeze);
}

//===================================================

void		Tank::setHP(int const HP) {
	_HP = HP;
}

void		Tank::setAmmo(int const ammo) {
	_ammo = ammo;
}

void		Tank::setSpeed(float const speed) {
	_speed = speed;
}

//===================================================

void		Tank::changeFreeze() {
	_freeze -= STEPTIME;
}

void		Tank::turn(int const way) {
	if ((_xyway.getWay() == RIGHT || _xyway.getWay() == LEFT) && (way == UP || way == DOWN))
		_xyway.setY(roundfTank(_xyway.getY()));
	if ((_xyway.getWay() == UP || _xyway.getWay() == DOWN) && (way == RIGHT || way == LEFT))
		_xyway.setX(roundfTank(_xyway.getX()));
	_xyway.setWay(way);
}

void		Tank::move(int const way) {
	if (_xyway.getWay() != way) {
		turn(way);
		return ;
	}
	if (way == UP && _xyway.getY() - 1.0f >= 0.0f)
		_xyway.setY(_xyway.getY() - 1.0f);
	if (way == RIGHT && _xyway.getX() + 1.0f < 13.0f)
		_xyway.setX(_xyway.getX() + 1.0f);
	if (way == DOWN && _xyway.getY() + 1.0f < 13.0f)
		_xyway.setY(_xyway.getY() + 1.0f);
	if (way == LEFT && _xyway.getX() - 1.0f >= 0.0f)
		_xyway.setX(_xyway.getX() - 1.0f);
}

void		Tank::reload() {
	_ammo++;
}

_Bool		Tank::takeDamage() {
	_HP--;
	if (!_HP)
		return (FALSE);
	return (TRUE);
}

//===================================================

Tank::~Tank() {}
