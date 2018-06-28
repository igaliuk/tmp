#include "BestTanks.h"

Bullet::Bullet(float const speed) {
	_power = 1;
	_speed = speed;
	_xyway.setX(0);
	_xyway.setY(0);
	_xyway.setWay(0);
}

int			Bullet::getPower() const {
	return (_power);
}

 float		Bullet::getSpeed() const {
	return (_speed);
}

XYWay		&Bullet::getXYWay() {
	return (_xyway);
}

void		Bullet::move(int const way) {
	_xyway.setWay(way);
	if (way == UP && _xyway.getY() - 1.0 >= 0.0)
		_xyway.setY(_xyway.getY() - 1.0);
	if (way == RIGHT && _xyway.getX() + 1.0 < 13.0)
		_xyway.setX(_xyway.getX() + 1.0);
	if (way == DOWN && _xyway.getY() + 1.0 < 13.0)
		_xyway.setY(_xyway.getY() + 1.0);
	if (way == LEFT && _xyway.getX() - 1.0 >= 0.0)
		_xyway.setX(_xyway.getX() - 1.0);
}

Bullet::~Bullet() {}
