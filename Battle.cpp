#include "BestTanks.h"

#include <fstream>
#include <sstream>

Battle::Battle() {
	_nc = new Nc();
	_controller = new Controller(_nc, _vecTexture, _vecPlayer, _vecBullet);
	_game = 1;
	_map = new char [HEIGHT_BATTLE * WIDTH_BATTLE + 1];
	for (int i = 0; i < HEIGHT_BATTLE * WIDTH_BATTLE + 1; i++)
		_map[i] = 0;
	_eagle = NULL;
}

//===================================================

void		Battle::init() {
	_nc->init();
}

void		Battle::choiseGame() {
	_nc->menu(_game);
	if (_game == 1 || _game == 2)
		this->company();
	if (_game == 3 || _game == 4)
		this->survival();
//	if (_game == 4)
//		_nc->controls();
	if (_game == 5)
		_nc->wantQuit();
}

//===================================================

void		Battle::company() {}

void		Battle::survival() {
	_eagle = new Eagle();

	initTextures(0);
	initPlayers();
	cycle();
}

//===================================================

void		Battle::initTextures(int const lvl) {
	ifstream		fin;
	char			buff[WIDTH_BATTLE + 1];
	Texture			*texture;
	
	openFileMap(&fin, lvl);
	for (int i = 0; i < HEIGHT_BATTLE; i++) {
		fin.getline(buff, WIDTH_BATTLE + 1);
		buff[WIDTH_BATTLE] = 0;
		for (int j = 0; j < WIDTH_BATTLE; j++) {
			if ((texture = this->typeTexture(buff[j], j, i)))
				_vecTexture.push_back(texture);
		}
	}
	fin.close();
}

void		Battle::openFileMap(ifstream * fin, int const lvl) const {
	fin->open("lvl/lvl00"); // алгоритм вібора нужного лвл
	if (!fin->is_open())
		std::exit(1); ///////////////////////////////////////////////// ERROR OPEN
}

Texture *	Battle::typeTexture(int const type, float const x, float const y) const {
	switch (type) {
		case '0':
			return (NULL);
		case '1':
			return (new Texture(1, 1, 0, 0.0, x, y));
		case '2':
			return (new Texture(2, 2, 0, 0, x, y));
		case '3':
			return (new Texture(3, 3, 0, 0, x, y));
		case '4':
			return (new Texture(4, 0, 1, 0, x, y));
		case '5':
			return (new Texture(5, 0, 1, 1, x, y));
		default:
			exit(1); ///////////////////////////////////////////////// ERROR MAP
	}
}

void		Battle::initPlayers() {
	Player *pl;

	pl = new Player(1, START_POS_X_PL1, START_POS_Y_PL1);
	_vecPlayer.push_back(pl);
	if (_game == 1 || _game == 3) {
		pl = new Player(2, START_POS_X_PL2, START_POS_Y_PL2);
		_vecPlayer.push_back(pl);
	}
}

//===================================================

_Bool		Battle::cycle() {
	int NTank = 0;

	while (TRUE) {
		for (int i = 0; i < _vecBullet.size(); i++) {
			_vecBullet[i]->move();
			checkBullet(i);
		}
		fillMap();
		_nc->printW2(_map);
		if (checkGameOver())
			return (FALSE);
		_controller->getKey();
		if (NTank == 20 && !_vecEnemy.size())
			break ;
	}
	return (TRUE);
}

void		Battle::fillMap() {
	XYWay		xyway;

	for (int i = 0; i < HEIGHT_BATTLE * WIDTH_BATTLE; i++)
		_map[i] = 0;
	xyway = _eagle->getXYWay();
	_map[roundfTank(xyway.getY() * WIDTH_BATTLE) + roundfTank(xyway.getX())] = (char)9;
	for (int i = 0; i < _vecTexture.size(); i++) {
		xyway = _vecTexture[i]->getXYWay();
		_map[roundfTank(xyway.getY() * WIDTH_BATTLE) + roundfTank(xyway.getX())] = (char)_vecTexture[i]->getType();
	}
//	for (int i = 0; i < _vecPlayer.size(); i++) {
//		xyway = _vecPlayer[i]->getXYWay();
//		_map[roundfTank(xyway.getY()) * WIDTH_BATTLE + roundfTank(xyway.getX())] += _vecPlayer[i]->getType() * 10;
//	}
//	for (int i = 0; i < _vecEnemy.size(); i++) {
//		xyway = _vecEnemy[i]->getXYWay();
//		_map[roundfTank(xyway.getY()) * WIDTH_BATTLE + roundfTank(xyway.getX())] += _vecEnemy[i]->getType() * 10;
//	}
//	for (int i = 0; i < _vecBullet.size(); i++) {
//		xyway = _vecBullet[i]->getXYWay();
//		_map[roundfTank(xyway.getY()) * WIDTH_BATTLE + roundfTank(xyway.getX())] += 90;
//	}
}

//===================================================

_Bool		Battle::checkGameOver() const {
	if (_eagle)
		return (FALSE);
	for (int i = 0; i < _vecPlayer.size(); i++)
		if (_vecPlayer[i]->getLifes() < 0)
			return(FALSE);
	return (TRUE);
}

void		Battle::checkBullet(int const i) {
	for (int j = 0; j < _vecBullet.size(); j++) {
		if (j == i)
			continue ;
		if (_vecBullet[j]->getXYWay() == _vecBullet[i]->getXYWay()) {
			_vecBullet[i]->changeStatus();
			_vecBullet[j]->changeStatus();
			if (i > j)
				_vecBullet.erase(_vecBullet.begin() + i, _vecBullet.begin() + j);
			else
				_vecBullet.erase(_vecBullet.begin() + j, _vecBullet.begin() + i);
			return ;
		}
	}
	if (_eagle->getXYWay() == _vecBullet[i]->getXYWay()) {
		_vecBullet[i]->changeStatus();
		_vecBullet.erase(_vecBullet.begin() + i);
		delete _eagle;
		_eagle = NULL;
		return ;
	}
	for (int j = 0; j < _vecTexture.size(); j++) {
		if (_vecTexture[j]->getXYWay() == _vecBullet[i]->getXYWay()) {
			if (_vecTexture[j]->getPassability())
				break ;
			_vecBullet[i]->changeStatus();
			_vecBullet.erase(_vecBullet.begin() + i);
			if (!_vecTexture[j]->takeDamage(_vecBullet[i]->getPower())) {
				delete _vecTexture[j];
				_vecTexture.erase(_vecTexture.begin() + j);
			}
			return ;
		}
	}
	for (int j = 0; j < _vecPlayer.size(); j++) {
		if (_vecPlayer[j]->getXYWay() == _vecBullet[i]->getXYWay()) {
			_vecBullet[i]->changeStatus();
			_vecBullet.erase(_vecBullet.begin() + i);
			if (!_vecPlayer[j]->takeDamage()) {
				_vecPlayer[j]->death();
			}
			return ;
		}
	}
	for (int j = 0; j < _vecEnemy.size(); j++) {
		if (_vecEnemy[j]->getXYWay() == _vecBullet[i]->getXYWay()) {
			_vecBullet[i]->changeStatus();
			_vecBullet.erase(_vecBullet.begin() + i);
			if (!_vecEnemy[j]->takeDamage()) {
				delete _vecEnemy[j];
				_vecEnemy.erase(_vecEnemy.begin() + j);
			}
			return ;
		}
	}
}

//===================================================

Battle::~Battle() {
	delete _nc;
	delete _controller;
	delete _map;
}




//void	print2()
//{
//	XYWay *xyway;
//	std::ofstream	fout;
//	fout.open("111");
//	if (!fout.is_open())
//	{
//		std::cout << "BAD FILE" << std::endl;
//		std::exit(1);
//	}
//
//	fout << "Players" << std::endl;
//	for (int i = 0; i < _vecPlayer.size(); i++) {
//		xyway = &_vecPlayer[i]->getXYWay();
//		fout << "x " << xyway->getX() << std::endl;
//		fout << "y " << xyway->getY() << std::endl;
//		fout << "w " << xyway->getWay() << std::endl;
//		fout << "a " << _vecPlayer[i]->getAmmo() << std::endl;
//		fout << "p " << _vecPlayer[i]->getType() << std::endl;
//		fout << std::endl;
//	}
//	fout << "Bullets" << std::endl;
//	for (int i = 0; i < _vecBullet.size(); i++) {
//		xyway = &_vecBullet[i]->getXYWay();
//		fout << "x " << xyway->getX() << std::endl;
//		fout << "y " << xyway->getY() << std::endl;
//		fout << "w " << xyway->getWay() << std::endl;
//		fout << std::endl;
//	}
//
//	fout.close();
//}