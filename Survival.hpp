#ifndef SURVIVAL_HPP
# define SURVIVAL_HPP

# include "BestTanks.h"

class Survival : public Game {

	private:

		Nc						* _nc;
		Controller				*_controller;
		int						_typeGame;
		Eagle *					_eagle;
		vector<Texture *>		_vecTexture;
		vector<Player *>		_vecPlayer;
		vector<Player *>		_vecEnemy;
		vector<Bullet *>		_vecBullet;

	public:

		Survival(Nc * nc, Controller * controller, int typeGame);

		~Survival();

		void	print2();
};

#endif
