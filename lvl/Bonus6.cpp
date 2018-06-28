#include "Bonus6.hpp"

Bonus6::Bonus6() {
	_type = 5;
	_xyway.x = -1;
	_xyway.y = -1;
	_xyway.way = 0;
	_skin = "@";
}

Bonus6::Bonus6(int const x, int const y) {
	_type = 5;
	_xyway.x = x;
	_xyway.y = y;
	_xyway.way = 0;
	_skin = "@";
}

int			Bonus6::getType() const {
	return (_type);
}

t_xyway		Bonus6::getXYWay() const {
	return (_xyway);
}

std::string	Bonus6::getSkin() const {
	return (_skin);
}

Bonus6::~Bonus6() {}

#endif
