#ifndef MENU_HPP
# define MENU_HPP

# include "BestTanks.h"

class Menu {

	private:

		string					_mapOfPassability;
		Nc						*_nc;
		Game					*_game;
		Controller				*_controller;
		int						_typeGame;

	public:

		Menu();

		void		init();
		void		choiseGame();

		~Menu();
};

#endif
