#include "BestTanks.h"

XYWay::XYWay() {}

XYWay &		XYWay::operator = (XYWay const & obj)
{
	this->setX(obj.getX());
	this->setY(obj.getY());
	this->setWay(obj.getWay());
	return (*this);
}

_Bool		XYWay::operator == (XYWay const & obj)
{
	if (this->getX() == obj.getX() && this->getY() == obj.getY())
		return (TRUE);
	return (FALSE);
}

//===================================================

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

//===================================================

XYWay::~XYWay() {}