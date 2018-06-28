#include "Bonus4.hpp"

Bonus4::Bonus4() {
	_type = 4;
	_xyway.x = -1;
	_xyway.y = -1;
	_xyway.way = 0;
	_skin = "@";
}

Bonus4::Bonus4(int const x, int const y) {
	_type = 4;
	_xyway.x = x;
	_xyway.y = y;
	_xyway.way = 0;
	_skin = "@";
}

int			Bonus4::getType() const {
	return (_type);
}

t_xyway		Bonus4::getXYWay() const {
	return (_xyway);
}

std::string	Bonus4::getSkin() const {
	return (_skin);
}

Bonus4::~Bonus4() {}

#endif
