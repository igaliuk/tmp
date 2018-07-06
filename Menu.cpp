#include "BestTanks.h"

Menu::Menu() {
	_mapOfPassability = "";
	_nc = new Nc();
	_controller = new Controller(_nc, _mapOfPassability);
	_game = NULL;
	_typeGame = 1;
}

//===================================================

void		Menu::init() {
	_nc->init();
}

void		Menu::choiseGame() {
	_nc->menu(_typeGame);
//	if (_typeGame == 1 || _typeGame == 2) {
//		_battle = new Company(_nc);
//		_battle->game(_typeGame);
//	}
	if (_typeGame == 3 || _typeGame == 4) {
		_game = new Survival(_nc, _controller, _typeGame, _mapOfPassability);
		_game->battle(); //////
	}
//	if (_typeGame == 4)
//		_nc->controls();
	if (_typeGame == 5)
		_nc->wantQuit();
}

//===================================================

Menu::~Menu() {
	delete _nc;
	delete _controller;
	delete _game;
}