#ifndef BATTLE_HPP
# define BATTLE_HPP

# include "BestTanks.h"

class Game {

	private:

		Nc						* _nc;
		Controller				* _controller;
		int						_typeGame;
		Eagle *					_eagle;
		vector<Texture *>		_vecTexture;
		vector<Player *>		_vecPlayer;
		vector<Player *>		_vecEnemy;
		vector<Bullet *>		_vecBullet;

	public:

		Game(Nc * nc, Controller * controller, int typeGame);

		void		initTextures(int const lvl);
		void		openFileMap(ifstream * fin, int const lvl) const;
		Texture *	typeTexture(int const type, float const x, float const y) const;
		void		initPlayers();

		_Bool		cycleBattle();

		_Bool		checkGameOver() const;
		void		checkBullet(int const i);

		~Game();
	
	
	void	print2();
};

#endif
