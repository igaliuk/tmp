#include "BestTanks.h"

Bullet::Bullet(float const speed) {
	_power = 1;
	_speed = speed;
	_xyway.setX(-1.0f);
	_xyway.setY(-1.0f);
	_xyway.setWay(0);
    _status = FALSE;
}

//===================================================

int			Bullet::getPower() const {
	return (_power);
}

 float		Bullet::getSpeed() const {
	return (_speed);
}

XYWay		&Bullet::getXYWay() {
	return (_xyway);
}

_Bool		Bullet::getStatus() {
	return (_status);
}

//===================================================

void           Bullet::setPower(int const power) {
    _power = power;
}

void        Bullet::setSpeed(float const speed) {
    _speed = speed;
}

void		Bullet::setXYWay(XYWay const & xyway) {
	_xyway = xyway;
}

//===================================================

void		Bullet::changeStatus() {
	if (_status)
		_status = FALSE;
	else
		_status = TRUE;
}

void		Bullet::move() {
	if (_xyway.getWay() == UP)
		_xyway.setY(_xyway.getY() - _speed);
	if (_xyway.getWay() == RIGHT)
		_xyway.setX(_xyway.getX() + _speed);
	if (_xyway.getWay() == DOWN)
		_xyway.setY(_xyway.getY() + _speed);
	if (_xyway.getWay() == LEFT)
		_xyway.setX(_xyway.getX() - _speed);
}

//===================================================

Bullet::~Bullet() {}
