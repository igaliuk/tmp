#include "BestTanks.h"

Player::Player(int const type, float const x, float const y) {
	_type = type;
    _respTime = RESP_TIME;
	_HP = 1;
	_ammo = 1;
	_speed = SPEED_TANK1;
	_xyway.setX(x);
	_xyway.setY(y);
	_xyway.setWay(UP);
    _freeze = 0;
	_bullet = new Bullet(SPEED_BULLET1);
	_bullet2 = new Bullet(SPEED_BULLET2);
    _rank = 0;
    _lifes = 3;
    _score = 0;
}

//===================================================

int			Player::getRank() const {
	return (_rank);
}

int			Player::getLifes() const {
	return (_lifes);
}

int			Player::getScore() const {
	return (_score);
}

//===================================================

void		Player::setRank(int const rank) {
	_rank = rank;
}

void		Player::setLifes(int const lifes) {
	_lifes = lifes;
}

void		Player::setScore(int const score) {
	_score = score;
}

//===================================================

Bullet *	Player::attack() {
	if (_ammo > 0) {
		_ammo--;
		if (!_bullet->getStatus()) {
			_bullet->changeStatus();
			_bullet->setXYWay(_xyway);
			return (_bullet);
		}
		if (!_bullet2->getStatus()) {
			_bullet2->changeStatus();
			_bullet2->setXYWay(_xyway);
			return (_bullet2);
		}
	}
	return (NULL);
}

void        Player::upRank() {
    _rank++;
    switch _rank {
        case 1:
            _speed = SPEED_TANK2;
            _bullet->setSpeed(SPEED_BULLET2);
            break ;
        case 2:
            _ammo++;
            break ;
        case 3:
            _bullet->setPower(2);
            _bullet2->setPower(2);
            break ;
        default:
            _rank--;
    }
}

void		Player::death() {
	_rank = 0;
	_HP = 1;
	_lifes--;
	_speed = SPEED_TANK1;
    _bullet->setSpeed(SPEED_BULLET1);
    _bullet->setPower(1);
    _bullet2->setPower(1);
	if (_type == 1) {
		_xyway.setX(START_POS_X_PL1);
		_xyway.setY(START_POS_Y_PL1);
	}
	else {
		_xyway.setX(START_POS_X_PL2);
		_xyway.setY(START_POS_Y_PL2);
	}
	_xyway.setWay(UP);
	_respTime = RESP_TIME;
}

//===================================================

Player::~Player() {
	delete _bullet;
	delete _bullet2;
}
