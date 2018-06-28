#ifndef BONUS4_HPP
# define BONUS4_HPP

# include "IBonus.hpp"

class Bonus4 : public IBonus {

	private:

		int				_type;
		t_xyway			_xyway;
		std::string		_skin;

	public:

		Bonus4();
		Bonus4(int const x, int const y);

//		virtual void bonusing();

		virtual int				getType() const;
		virtual t_xyway			getXYWay() const;
		virtual std::string		getSkin() const;

		virtual ~Bonus4();
};

#endif
