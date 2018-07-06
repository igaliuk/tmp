#ifndef BATTLE_HPP
# define BATTLE_HPP

# include "BestTanks.h"

class Game {

	private:

		Nc						* _nc;
		Controller				* _controller;
		int						_typeGame;
		vector<Player *>		_vecPlayer;
		vector<Texture *>		_vecTexture;
		vector<Tank *>			_vecTank;
		vector<Bullet *>		_vecBullet;
		string					& _mapOfPassability;

	public:

		Game(Nc * nc, Controller * controller, int typeGame, string & mapOfPassability);

		_Bool		battle();

		void		initTextures(int const lvl);
		void		openFileMap(ifstream * fin, int const lvl) const;
		Texture *	typeTexture(int const type, float const x, float const y) const;
		void		initPlayersEagle();
		Tank *		initEnemy(int const type, float const x, float const y);

		void		incubatorEnemy(int const NTank);
		void		buildMapOfPassability();

		_Bool		checkGameOver() const;
		void		checkBullet(int const i);
		string		checkPassability(int const x, int const y) const;

		~Game();
	
	
	void	print2();
};

#endif
