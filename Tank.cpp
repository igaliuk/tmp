#include "BestTanks.h"

Tank::Tank() {
	_type = 0;
	_resp = 0;
	_HP = 0;
	_speed = 0;
	_xyway.setX(-1.0f);
	_xyway.setY(-1.0f);
	_xyway.setWay(0);
	_freeze = 0;
	_bullet = NULL;
	_bullet2 = NULL;
}

//===================================================

int			Tank::getType() const {
	return (_type);
}

int            Tank::getResp() const {
    return (_resp);
}

int			Tank::getHP() const {
	return (_HP);
}

float		Tank::getSpeed() const {
	return (_speed);
}

XYWay &		Tank::getXYWay() {
	return (_xyway);
}

int			Tank::getFreeze() const {
	return (_freeze);
}

//===================================================

void		Tank::setType(int const type) {
	_type = type;
}

void		Tank::setHP(int const HP) {
	_HP = HP;
}

void		Tank::setSpeed(float const speed) {
	_speed = speed;
}

void		Tank::setFreeze(int const freeze) {
	_freeze = freeze;
}

//===================================================

void		Tank::changeFreeze() {
	_freeze -= STEP_TIME;
}

void		Tank::turn(int const way) {
	int		tmpWay;

	tmpWay = _xyway.getWay();
	_xyway.setWay(way);
	if ((tmpWay == RIGHT || tmpWay == LEFT) && (way == UP || way == DOWN))
		_xyway.setY(roundfTank(_xyway.getY()));
	if ((tmpWay == UP || tmpWay == DOWN) && (way == RIGHT || way == LEFT))
		_xyway.setX(roundfTank(_xyway.getX()));
}

void		Tank::move(int const way, string const mapOfPassability) {
	float		f = 0.0;

	if (_xyway.getWay() != way)
		turn(way);
	if (way == UP && (f = _xyway.getY() - _speed) >= 0.0f && (_xyway.getYRound() == _xyway.getYRoundWithShift(0 - _speed) || mapOfPassability[(_xyway.getYRoundWithShift(0 - _speed) * WIDTH_BATTLE) + _xyway.getXRound()] == '1'))
		_xyway.setY(f);
	if (way == RIGHT && (f = _xyway.getX() + _speed) <= static_cast<float>(WIDTH_BATTLE - 1) && (_xyway.getXRound() == _xyway.getXRoundWithShift(_speed) || mapOfPassability[(_xyway.getYRound() * WIDTH_BATTLE) + _xyway.getXRoundWithShift(_speed)] == '1'))
		_xyway.setX(f);
	if (way == DOWN && (f = _xyway.getY() + _speed) <= static_cast<float>(HEIGHT_BATTLE - 1) && (_xyway.getYRound() == _xyway.getYRoundWithShift(_speed) || mapOfPassability[(_xyway.getYRoundWithShift(_speed) * WIDTH_BATTLE) + _xyway.getXRound()] == '1'))
		_xyway.setY(f);
	if (way == LEFT && (f = _xyway.getX() - _speed) >= 0.0f && (_xyway.getXRound() == _xyway.getXRoundWithShift(0 - _speed) || mapOfPassability[(_xyway.getYRound() * WIDTH_BATTLE) + _xyway.getXRoundWithShift(0 - _speed)] == '1'))
		_xyway.setX(f);
}

_Bool		Tank::takeDamage() {
	_HP--;
	if (!_HP)
		return (FALSE);
	return (TRUE);
}

//===================================================

Tank::~Tank() {}
