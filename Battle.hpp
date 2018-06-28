#ifndef BATTLE_HPP
# define BATTLE_HPP

# include "BestTanks.h"

class Battle {

	private:

		Nc						*_nc;
		Controller				*_controller;
		int						_game;
		int						_map[HEIGHT_BATTLE][WIDTH_BATTLE];
		vector<Texture *>		_vecTexture;
		vector<Player *>		_vecPlayer;
		vector<Player *>		_vecEnemy;
		vector<Bullet *>		_vecBullet;

	public:
	
		Battle();
		
		void		init();
		void		choiseGame();
		void		initTextures(int const lvl);
		Texture *	typeTexture(int const type, int const x, int const y) const;
		void		initPlayers();
		void		company();
		void		survival();
		void		fillMap();
	
		int			roundfBattle(float const f);
	
		~Battle();
	
	
	
	void	print2();
};

#endif
