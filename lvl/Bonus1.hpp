#ifndef BONUS1_HPP
# define BONUS1_HPP

# include "IBonus.hpp"

class Bonus1 : public IBonus {

	private:

		int				_type;
		t_xyway			_xyway;
		std::string		_skin;

	public:

		Bonus1();
		Bonus1(int const x, int const y);

//		virtual void bonusing();

		virtual int				getType() const;
		virtual t_xyway			getXYWay() const;
		virtual std::string		getSkin() const;

		virtual ~Bonus1();
};

#endif
