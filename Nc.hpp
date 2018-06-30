#ifndef NC_HPP
# define NC_HPP

# include "BestTanks.h"

class Nc {

private:

	WINDOW			*_win1;
	WINDOW			*_win2;
	WINDOW			*_win3;
	int				_key;
	_Bool			_pause;

public:

	Nc();

	int			getKey() const;
	_Bool		getPause() const;

	void		setKey(int const key);

	void		init();
	void		init_border();
	void		refreshWindows() const;
	void		menu(int & game) const;
	void		changePause();
	void		wantPause();
	void		wantQuit();
	void		printW2(char * map) const;

	~Nc();
};

#endif
