#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "BestTanks.h"

class Player : public Tank {

	private:

		int				_rank;
		int				_lifes;
		int				_score;

	public:

		Player(int const type, float const x, float const y);

		int						getRank() const;
		int						getLifes() const;
		int						getScore() const;

		void					setRank(int const rank);
		void					setLifes(int const lifes);
		void					setScore(int const score);

		virtual Bullet *		attack();
    void       upRank();
		void					death();

		virtual ~Player();
};

#endif
