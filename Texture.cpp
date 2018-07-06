#include "BestTanks.h"

Texture::Texture(int const type, int const power, int const passability, int const permeability, float const speed, float const x, float const y) {
	_type = type;
	_power = power;
	_passability = passability;
	_permeability = permeability;
	_speed = speed;
	_xyway.setX(x);
	_xyway.setY(y);
	_xyway.setWay(0);
}

//===================================================

int			Texture::getType() const {
	return (_type);
}

int			Texture::getPower() const {
	return (_power);
}

int			Texture::getPassability() const {
	return (_passability);
}

int			Texture::getPermeability() const {
	return (_permeability);
}

float		Texture::getSpeed() const {
	return (_speed);
}

XYWay &		Texture::getXYWay() {
	return (_xyway);
}

//===================================================

_Bool		Texture::takeDamage(int const power) {
	if (_power == power)
		return (FALSE);
	return (TRUE);
}

//===================================================

Texture::~Texture() {}
