#include "Bonus1.hpp"

Bonus1::Bonus1() {
	_type = 1;
	_xyway.x = -1;
	_xyway.y = -1;
	_xyway.way = 0;
	_skin = "@";
}

Bonus1::Bonus1(int const x, int const y) {
	_type = 1;
	_xyway.x = x;
	_xyway.y = y;
	_xyway.way = 0;
	_skin = "@";
}

int			Bonus1::getType() const {
	return (_type);
}

t_xyway		Bonus1::getXYWay() const {
	return (_xyway);
}

std::string	Bonus1::getSkin() const {
	return (_skin);
}

Bonus1::~Bonus1() {}

#endif
