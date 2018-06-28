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

Bullet *	Tank::attack() {
	if (_ammo > 0) {
		_ammo--;
		return (new Bullet(_power, _bSpeed, _xyway, *this));
	}
	return (NULL);
}

void		Tank::move(int const way) {
	_xyway.setWay(way);
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

Tank::~Tank() {}
