#ifndef CONTROLLER_HPP
# define CONTROLLER_HPP

# include "BestTanks.h"

class Nc;

class Controller {

	private:

		Nc						*_nc;
		string					& _mapOfPassability;
//		vector<Player *>		&_vecPlayer;
//		vector<Bullet *>		&_vecBullet;

	public:

		Controller(Nc * nc, string & mapOfPassability);
//		Controller(Nc * nc, vector<Texture *> & vecTexture, vector<Player *> & vecPlayer, vector<Bullet *> & vecBullet);

		void			getKey(vector<Player *> & vecPlayer, vector<Bullet *> & vecBullet);

		~Controller();
};

#endif