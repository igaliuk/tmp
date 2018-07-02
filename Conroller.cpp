#include "BestTanks.h"

//Controller::Controller(Nc * nc, vector<Texture *> & vecTexture, vector<Player *> & vecPlayer, vector<Bullet *> & vecBullet) : _vecTexture(vecTexture), _vecPlayer(vecPlayer), _vecBullet(vecBullet) {
Controller::Controller(Nc * nc) {
	_nc = nc;
}

void		Controller::getKey() {
	Bullet *bullet;

//	_nc->setKey(getch());
//	if (_nc->getKey() == KEY_QUIT)
//		_nc->wantQuit();
//	else if (_nc->getKey() == KEY_PAUSE)
//		_nc->wantPause();
//
//	else if (_nc->getKey() == KEY_PL1_UP)
//		_vecPlayer[0]->move(UP);
//	else if (_nc->getKey() == KEY_PL1_RIGHT)
//		_vecPlayer[0]->move(RIGHT);
//	else if (_nc->getKey() == KEY_PL1_DOWN)
//		_vecPlayer[0]->move(DOWN);
//	else if (_nc->getKey() == KEY_PL1_LEFT)
//		_vecPlayer[0]->move(LEFT);
//	else if (_nc->getKey() == KEY_PL1_FIRE) {
//		if ((bullet = _vecPlayer[0]->attack()))
//			_vecBullet.push_back(bullet);
//	}
//
//	else if (_nc->getKey() == KEY_PL2_UP)
//	_vecPlayer[1]->move(UP);
//	else if (_nc->getKey() == KEY_PL2_RIGHT)
//	_vecPlayer[1]->move(RIGHT);
//	else if (_nc->getKey() == KEY_PL2_DOWN)
//	_vecPlayer[1]->move(DOWN);
//	else if (_nc->getKey() == KEY_PL2_LEFT)
//	_vecPlayer[1]->move(LEFT);
//	else if (_nc->getKey() == KEY_PL2_FIRE) {
//		if ((bullet = _vecPlayer[1]->attack()))
//		_vecBullet.push_back(bullet);
//	}
}

Controller::~Controller() {}
