#ifndef BONUS6_HPP
# define BONUS6_HPP

# include "IBonus.hpp"

class Bonus6 : public IBonus {

	private:

		int				_type;
		t_xyway			_xyway;
		std::string		_skin;

	public:

		Bonus6();
		Bonus6(int const x, int const y);

//		virtual void bonusing();

		virtual int				getType() const;
		virtual t_xyway			getXYWay() const;
		virtual std::string		getSkin() const;

		virtual ~Bonus6();
};

#endif
