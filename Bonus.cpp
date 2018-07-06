#include "BestTanks.h"

Bonus::Bonus(float const x, float const y) {
	_type = 0;
	_xyway.setX(x);
	_xyway.setY(y);
	_xyway.setWay(0);
}

//===================================================

int			Bonus::getType() const {
	return (_type);
}

XYWay &		Bonus::getXYWay() {
	return (_xyway);
}

//===================================================

Bonus::~Bonus() {}
