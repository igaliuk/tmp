#include "BestTanks.h"

Texture::Texture(int const type, int const power, int const passability, float const speed, int const x, int const y) {
	_type = type;
	_power = power;
	_passability = passability;
	_speed = speed;
	_xyway.setX(x);
	_xyway.setY(y);
	_xyway.setWay(0);
}

int			Texture::getType() const {
	return (_type);
}

int			Texture::getPower() const {
	return (_power);
}

int			Texture::getPassability() const {
	return (_passability);
}

float		Texture::getSpeed() const {
	return (_speed);
}

XYWay		&Texture::getXYWay() {
	return (_xyway);
}

void		Texture::destroed() {
	this->~Texture();
}

Texture::~Texture() {}
