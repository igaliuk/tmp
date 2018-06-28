#include "BestTanks.h"

float		XYWay::getX() const {
	return (_x);
}

float		XYWay::getY() const {
	return (_y);
}

int			XYWay::getWay() const {
	return (_way);
}

//===================================================

void		XYWay::setX(float const x) {
	_x = x;
}

void		XYWay::setY(float const y) {
	_y = y;
}

void		XYWay::setWay(int const way) {
	_way = way;
}