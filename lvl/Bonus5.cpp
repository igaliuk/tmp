#include "Bonus5.hpp"

Bonus5::Bonus5() {
	_type = 5;
	_xyway.x = -1;
	_xyway.y = -1;
	_xyway.way = 0;
	_skin = "@";
}

Bonus5::Bonus5(int const x, int const y) {
	_type = 5;
	_xyway.x = x;
	_xyway.y = y;
	_xyway.way = 0;
	_skin = "@";
}

int			Bonus5::getType() const {
	return (_type);
}

t_xyway		Bonus5::getXYWay() const {
	return (_xyway);
}

std::string	Bonus5::getSkin() const {
	return (_skin);
}

Bonus5::~Bonus5() {}

#endif
