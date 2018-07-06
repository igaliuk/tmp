#include "BestTanks.h"

#include <fstream>
#include <sstream>

Game::Game(Nc * nc, Controller * controller, int typeGame, string & mapOfPassability) : _mapOfPassability(mapOfPassability) {
	_nc = nc;
	_controller = controller;
	_typeGame = typeGame;
}

//===================================================

_Bool		Game::battle() {
	int				NTank = 0;
	int				respTime = 0;
	timeval			te; /// struct
	long long		intervalTime; ///

	initTextures(0);
	initPlayersEagle();

	gettimeofday(&te, NULL); ///
	while (TRUE) {
		intervalTime = 0 - (te.tv_sec * 1000 + te.tv_usec / 1000); ///
		for (int i = 0; i < _vecBullet.size(); i++) {
			_vecBullet[i]->move();
			checkBullet(i);
		}
		buildMapOfPassability();
		for (int i = 3; i < _vecTank.size(); i++) {
			_vecTank[i]->move(DOWN, _mapOfPassability);
		}
		_nc->printW2(_vecTexture, _vecTank, _vecBullet);
		if (checkGameOver())
			return (FALSE);
		if (NTank < NUM_OF_ENEMY_GAME && respTime <= 0) {
			incubatorEnemy(++NTank);
			respTime = RESP_TIME;
		}
		_controller->getKey(_vecPlayer, _vecBullet);
		if (NTank == NUM_OF_ENEMY_GAME && _vecTank.size() == 3)
			break ;
		intervalTime += te.tv_sec * 1000 + te.tv_usec / 1000; ///
		usleep(STEP_TIME - intervalTime);
		respTime -= STEP_TIME;
	}
	return (TRUE);
}

//===================================================

void		Game::incubatorEnemy(int const NTank) {
	static int		position = 1;
	Tank			*tank;

	switch (position) {
		case 1:
			tank = initEnemy(5, START_POS_X_EN1, START_POS_Y_EN1); //// type
			break ;
		case 2:
			tank = initEnemy(5, START_POS_X_EN2, START_POS_Y_EN2);
			break ;
		default:
			tank = initEnemy(5, START_POS_X_EN3, START_POS_Y_EN3);
	}
	_vecTank.push_back(tank);
	if (++position == 4 || NTank == NUM_OF_ENEMY_GAME)
		position = 1;
}

void		Game::buildMapOfPassability() {
	_mapOfPassability = "";
	for (int i = 0; i < HEIGHT_BATTLE; i++)
		for (int j = 0; j < WIDTH_BATTLE; j++)
			_mapOfPassability += checkPassability(j, i);
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
			if ((texture = typeTexture(buff[j], static_cast<float>(j), static_cast<float>(i))))
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
			return (new Texture(1, 1, 0, 0, 0.0, x, y));
		case '2':
			return (new Texture(2, 2, 0, 0, 0.0, x, y));
		case '3':
			return (new Texture(3, 0, 0, 1, 0.0, x, y));
		case '4':
			return (new Texture(4, 0, 1, 1, 0.0, x, y));
		case '5':
			return (new Texture(5, 0, 1, 1, 1.0, x, y));
		default:
			exit(1); ///////////////////////////////////////////////// ERROR MAP
	}
}

void		Game::initPlayersEagle() {
	Player		*player;

	_vecTank.push_back(new Eagle());
	player = new Player(1, START_POS_X_PL1, START_POS_Y_PL1);
	_vecPlayer.push_back(player);
	_vecTank.push_back(player);
	player = new Player(2, START_POS_X_PL2, START_POS_Y_PL2);
	_vecPlayer.push_back(player);
	if (_typeGame == 1 || _typeGame == 3)
		_vecTank.push_back(player);
}

Tank *		Game::initEnemy(int const type, float const x, float const y) {
	switch (type) {
		case 3:
			return(new Enemy(type, 1, SPEED_TANK1, x, y, SPEED_BULLET1));
		case 4:
			return(new Enemy(type, 1, SPEED_TANK3, x, y, SPEED_BULLET1));
		case 5:
			return(new Enemy(type, 1, SPEED_TANK1, x, y, SPEED_BULLET2));
		default:
			return(new Enemy(type, 4, SPEED_TANK1, x, y, SPEED_BULLET1));
	}
}

//===================================================

_Bool		Game::checkGameOver() const {
	if (!_vecTank.front()->getType())
		return (TRUE);
	for (int i = 0; i < _vecPlayer.size(); i++)
		if (_vecPlayer[i]->getLifes() >= 0)
			return(FALSE);
	return (TRUE);
}

void		Game::checkBullet(int const i) {
	{
		float x = _vecBullet[i]->getXYWay().getXRound();
		float y = _vecBullet[i]->getXYWay().getYRound();
		if (x < 0.0f || x > WIDTH_BATTLE - 1.0f || y < 0.0f || y > HEIGHT_BATTLE - 1.0f ) {
			_vecBullet[i]->changeStatus();
			_vecBullet.erase(_vecBullet.begin() + i);
			return ;
		}
	}
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
	for (int j = 0; j < _vecTexture.size(); j++) {
		if (_vecTexture[j]->getXYWay() == _vecBullet[i]->getXYWay()) {
			if (_vecTexture[j]->getPermeability())
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
	if (_vecTank.front()->getXYWay() == _vecBullet[i]->getXYWay()) {
		_vecBullet[i]->changeStatus();
		_vecBullet.erase(_vecBullet.begin() + i);
		if (!_vecTank.front()->takeDamage())
			_vecTank.front()->setType(0);
		return ;
	}
	for (int j = 0; j < _vecPlayer.size(); j++) {
		if (_vecTank[j]->getXYWay() == _vecBullet[i]->getXYWay()) {
			_vecBullet[i]->changeStatus();
			_vecBullet.erase(_vecBullet.begin() + i);
			if (!_vecPlayer[j - 1]->takeDamage())
				_vecPlayer[j - 1]->death();
			return ;
		}
	}
	for (int j = 3; j < _vecTank.size(); j++) {
		if (_vecTank[j]->getXYWay() == _vecBullet[i]->getXYWay()) {
			_vecBullet[i]->changeStatus();
			_vecBullet.erase(_vecBullet.begin() + i);
			if (!_vecTank[j]->takeDamage()) {
				delete _vecTank[j];
				_vecTank.erase(_vecTank.begin() + j);
			}
			return ;
		}
	}
}

string		Game::checkPassability(int const x, int const y) const {
	XYWay		xyway(static_cast<float const>(x), static_cast<float const>(y));

	for (int j = 0; j < _vecTexture.size(); j++)
		if (_vecTexture[j]->getXYWay() == xyway && !_vecTexture[j]->getPassability())
			return ("0");
	for (int j = 0; j < _vecTank.size(); j++)
		if (_vecTank[j]->getXYWay() == xyway)
			return ("0");
	return ("1");
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