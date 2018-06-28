#ifndef BONUS2_HPP
# define BONUS2_HPP

# include "IBonus.hpp"

class Bonus2 : public IBonus {

	private:

		int				_type;
		t_xyway			_xyway;
		std::string		_skin;

	public:

		Bonus2();
		Bonus2(int const x, int const y);

//		virtual void bonusing();

		virtual int				getType() const;
		virtual t_xyway			getXYWay() const;
		virtual std::string		getSkin() const;

		virtual ~Bonus2();
};

#endif
