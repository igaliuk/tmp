#include "BestTanks.h"

#include <fstream>
#include <sstream>

Battle::Battle() {
	_nc = new Nc();
	_controller = new Controller(_nc, _vecTexture, _vecPlayer, _vecBullet);
	_game = 0;
	for (int i = 0; i < HEIGHT_BATTLE; i++)
		for (int j = 0; j < WIDTH_BATTLE; j++)
			_map[i][j] = 0;
}

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

void		Battle::initTextures(int const lvl) {
	ifstream	fin;
	char		buff[WIDTH_BATTLE + 1];
	Texture		*texture;

	fin.open("lvl/lvl01");
	if (!fin.is_open())
	{
		std::cout << "BAD FILE" << std::endl;
		std::exit(1);
	}
	for (int i = 0; i < HEIGHT_BATTLE; i++) {
		fin.getline(buff, WIDTH_BATTLE + 1);
		buff[WIDTH_BATTLE] = 0;
		for (int j = 0; j < WIDTH_BATTLE; j++) {
			if ((texture = this->typeTexture(buff[j], j, i))) {
				_vecTexture.push_back(texture);
				_map[i][j] = buff[j];
			}
		}
	}
	fin.close();
}

Texture *	Battle::typeTexture(int const type, int const x, int const y) const {
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
			exit(-1); ///////////////////////////////////////////////// ERROR MAP
	}
}

void		Battle::initPlayers() {
	Player *pl;

	pl = new Player(1);
	_vecPlayer.push_back(pl);
	if (_game == 1 || _game == 3) {
		pl = new Player(2);
		_vecPlayer.push_back(pl);
	}
}

void		Battle::company() {
	initTextures(0);
	initPlayers();
	while (TRUE) {
		this->fillMap();
		_nc->printW1(_map);
		_controller->getKey();
	}
}

void		Battle::survival() {}

void		Battle::fillMap() {
	XYWay const		*xyway;

	for (int i = 0; i < _vecPlayer.size(); i++) {
		xyway = &_vecPlayer[i]->getXYWay();
		_map[roundfBattle(xyway->getY())][roundfBattle(xyway->getX())] += _vecPlayer[i]->getType() * 10;
	}
	for (int i = 0; i < _vecEnemy.size(); i++) {
		xyway = &_vecEnemy[i]->getXYWay();
		_map[roundfBattle(xyway->getY())][roundfBattle(xyway->getX())] += _vecEnemy[i]->getType() * 10;
	}
	for (int i = 0; i < _vecBullet.size(); i++) {
		xyway = &_vecBullet[i]->getXYWay();
		_map[roundfBattle(xyway->getY())][roundfBattle(xyway->getX())] += 90;
	}
}

int			roundfBattle(float const f) {
	return (static_cast<int>(roundf(f)));
}


Battle::~Battle() {
	delete _nc;
	delete _controller;
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