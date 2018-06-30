#ifndef BATTLE_HPP
# define BATTLE_HPP

# include "BestTanks.h"

class Battle {

	private:

		Nc						*_nc;
		Controller				*_controller;
		int						_game;
		char					*_map;
		Eagle *					_eagle;
		vector<Texture *>		_vecTexture;
		vector<Player *>		_vecPlayer;
		vector<Player *>		_vecEnemy;
		vector<Bullet *>		_vecBullet;

	public:

		Battle();

		void		init();
		void		choiseGame();

		void		company();
		void		survival();

		void		initTextures(int const lvl);
		void		openFileMap(ifstream * fin, int const lvl) const;
		Texture *	typeTexture(int const type, float const x, float const y) const;
		void		initPlayers();

		void		fillMap();
		_Bool		cycle();

		_Bool		checkGameOver() const;
		void		checkBullet(int const i);

		~Battle();
	
	
	void	print2();
};

#endif
