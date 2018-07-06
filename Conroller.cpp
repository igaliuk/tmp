#include "BestTanks.h"

//Controller::Controller(Nc * nc, vector<Texture *> & vecTexture, vector<Player *> & vecPlayer, vector<Bullet *> & vecBullet) : _vecTexture(vecTexture), _vecPlayer(vecPlayer), _vecBullet(vecBullet) {
Controller::Controller(Nc * nc, string & mapOfPassability) : _mapOfPassability(mapOfPassability) {
	_nc = nc;
}

void		Controller::getKey(vector<Player *> & vecPlayer, vector<Bullet *> & vecBullet) {
	Bullet *bullet;

	_nc->setKey(getch());
	if (_nc->getKey() == KEY_QUIT)
		_nc->wantQuit();
	else if (_nc->getKey() == KEY_PAUSE)
		_nc->wantPause();

	else if (_nc->getKey() == KEY_PL1_UP)
		vecPlayer[0]->move(UP, _mapOfPassability);
	else if (_nc->getKey() == KEY_PL1_RIGHT)
		vecPlayer[0]->move(RIGHT, _mapOfPassability);
	else if (_nc->getKey() == KEY_PL1_DOWN)
		vecPlayer[0]->move(DOWN, _mapOfPassability);
	else if (_nc->getKey() == KEY_PL1_LEFT)
		vecPlayer[0]->move(LEFT, _mapOfPassability);
	else if (_nc->getKey() == KEY_PL1_FIRE) {
		if ((bullet = vecPlayer[0]->attack()))
			vecBullet.push_back(bullet);
	}

	else if (_nc->getKey() == KEY_PL2_UP)
	vecPlayer[1]->move(UP, _mapOfPassability);
	else if (_nc->getKey() == KEY_PL2_RIGHT)
	vecPlayer[1]->move(RIGHT, _mapOfPassability);
	else if (_nc->getKey() == KEY_PL2_DOWN)
	vecPlayer[1]->move(DOWN, _mapOfPassability);
	else if (_nc->getKey() == KEY_PL2_LEFT)
	vecPlayer[1]->move(LEFT, _mapOfPassability);
	else if (_nc->getKey() == KEY_PL2_FIRE) {
		if ((bullet = vecPlayer[1]->attack()))
		vecBullet.push_back(bullet);
	}
}

Controller::~Controller() {}
