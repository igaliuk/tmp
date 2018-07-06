#include "BestTanks.h"

XYWay::XYWay() {
	_x = 0.0f;
	_y = 0.0f;
	_way = 0;
}

XYWay::XYWay(float const x, float const y) {
	_x = x;
	_y = y;
	_way = 0;
}

XYWay &		XYWay::operator = (XYWay const & obj)
{
	this->setX(obj.getX());
	this->setY(obj.getY());
	this->setWay(obj.getWay());
	return (*this);
}

_Bool		XYWay::operator == (XYWay const & obj)
{
	if (this->getXRound() == obj.getXRound() && this->getYRound() == obj.getYRound())
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

int			XYWay::getXRound() const {
	return (static_cast<int>(roundf(_x)));
}

int			XYWay::getYRound() const {
	return (static_cast<int>(roundf(_y)));
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

void		XYWay::smartShift()
{
	if (_way == UP)
		_y--;
	else if (_way == DOWN)
		_y++;
	else if (_way == RIGHT)
		_x++;
	else if (_way == LEFT)
		_x--;
}

int			XYWay::getXRoundWithShift(float const shift) const {
	return (static_cast<int>(roundf(_x + shift)));
}

int			XYWay::getYRoundWithShift(float const shift) const {
	return (static_cast<int>(roundf(_y + shift)));
}

//===================================================

XYWay::~XYWay() {}