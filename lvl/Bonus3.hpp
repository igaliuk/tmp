#ifndef BONUS3_HPP
# define BONUS3_HPP

# include "IBonus.hpp"

class Bonus3 : public IBonus {

	private:

		int				_type;
		t_xyway			_xyway;
		std::string		_skin;

	public:

		Bonus3();
		Bonus3(int const x, int const y);

//		virtual void bonusing();

		virtual int				getType() const;
		virtual t_xyway			getXYWay() const;
		virtual std::string		getSkin() const;

		virtual ~Bonus3();
};

#endif
