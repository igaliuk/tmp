#include "BestTanks.h"

#include <fstream>
#include <sstream>

Game::Game(Nc * nc, Controller * controller, int typeGame) {
	_nc = nc;
	_controller = controller;
	_typeGame = typeGame;
	_eagle = NULL;
}

//===================================================

void		Game::initTextures(int const lvl) {
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

void		Game::openFileMap(ifstream * fin, int const lvl) const {
	fin->open("lvl/lvl00"); // алгоритм вібора нужного лвл
	if (!fin->is_open())
		std::exit(1); ///////////////////////////////////////////////// ERROR OPEN
}

Texture *	Game::typeTexture(int const type, float const x, float const y) const {
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

void		Game::initPlayers() {
	Player *pl;

	pl = new Player(1, START_POS_X_PL1, START_POS_Y_PL1);
	_vecPlayer.push_back(pl);
	if (_typeGame == 1 || _typeGame == 3) {
		pl = new Player(2, START_POS_X_PL2, START_POS_Y_PL2);
		_vecPlayer.push_back(pl);
	}
}

//===================================================

_Bool		Game::cycleBattle() {
	int NTank = 0;
	_eagle = new Eagle();

//	initTextures(0); ///////////
	initPlayers(); ///////////

	while (TRUE) {
		for (int i = 0; i < _vecBullet.size(); i++) {
			_vecBullet[i]->move();
			checkBullet(i);
		}
//		_nc->printW2(*_eagle, _vecTexture, _vecPlayer, _vecEnemy, _vecBullet);
		
		XYWay	xywa1;
		float	x = 0, x2 = 0;
		float	y = 0, y2 = 0;
		float	w = 0, w2 = 0;
		
		xywa1 = _eagle->getXYWay();
		x = xywa1.getX();
		y = xywa1.getY();
		w = xywa1.getWay();
		x2 = _eagle->getXYWay().getX();
		y2 = _eagle->getXYWay().getY();
		w2 = _eagle->getXYWay().getWay();
		
		if (checkGameOver())
			return (FALSE);
//		_controller->getKey();
		if (NTank == 20 && !_vecEnemy.size())
			break ;
	}
	return (TRUE);
}

//===================================================

_Bool		Game::checkGameOver() const {
	if (_eagle)
		return (FALSE);
	for (int i = 0; i < _vecPlayer.size(); i++)
		if (_vecPlayer[i]->getLifes() < 0)
			return(FALSE);
	return (TRUE);
}

void		Game::checkBullet(int const i) {
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

Game::~Game() {}




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