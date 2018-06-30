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
		int				_freeze;
		Bullet			*_bullet;
		Bullet			*_bullet2;

	public:

		Player();
		Player(int const type, float const x, float const y);

		int						getRank() const;
		int						getLifes() const;
		int						getScore() const;

		void					setRank(int const rank);
		void					setLifes(int const lifes);
		void					setScore(int const score);

		virtual Bullet *		attack();
		void					death();

		virtual ~Player();
};

#endif