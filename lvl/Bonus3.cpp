#include "Bonus3.hpp"

Bonus3::Bonus3() {
	_type = 3;
	_xyway.x = -1;
	_xyway.y = -1;
	_xyway.way = 0;
	_skin = "@";
}

Bonus3::Bonus3(int const x, int const y) {
	_type = 3;
	_xyway.x = x;
	_xyway.y = y;
	_xyway.way = 0;
	_skin = "@";
}

int			Bonus3::getType() const {
	return (_type);
}

t_xyway		Bonus3::getXYWay() const {
	return (_xyway);
}

std::string	Bonus3::getSkin() const {
	return (_skin);
}

Bonus3::~Bonus3() {}

#endif
