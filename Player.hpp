#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "BestTanks.h"

class Player : public Tank {

	private:

		int				_type;
		int				_rank;
		int				_HP;
		int				_lifes;
		int				_score;
		int				_ammo;
		float			_speed;
		XYWay			_xyway;
		Bullet			*_bullet;

	public:

		Player();
		Player(int const type, int const x, int const y);

		int						getRank() const;
		int						getLifes() const;
		int						getScore() const;

		void					setRank(int const rank);
		void					setLifes(int const lifes);
		void					setScore(int const score);

		virtual ~Player();
};

#endif