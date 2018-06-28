#include "Bonus2.hpp"

Bonus2::Bonus2() {
	_type = 2;
	_xyway.x = -1;
	_xyway.y = -1;
	_xyway.way = 0;
	_skin = "@";
}

Bonus2::Bonus2(int const x, int const y) {
	_type = 2;
	_xyway.x = x;
	_xyway.y = y;
	_xyway.way = 0;
	_skin = "@";
}

int			Bonus2::getType() const {
	return (_type);
}

t_xyway		Bonus2::getXYWay() const {
	return (_xyway);
}

std::string	Bonus2::getSkin() const {
	return (_skin);
}

Bonus2::~Bonus2() {}

#endif
