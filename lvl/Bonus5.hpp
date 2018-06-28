#ifndef BONUS5_HPP
# define BONUS5_HPP

# include "IBonus.hpp"

class Bonus5 : public IBonus {

	private:

		int				_type;
		t_xyway			_xyway;
		std::string		_skin;

	public:

		Bonus5();
		Bonus5(int const x, int const y);

//		virtual void bonusing();

		virtual int				getType() const;
		virtual t_xyway			getXYWay() const;
		virtual std::string		getSkin() const;

		virtual ~Bonus5();
};

#endif
