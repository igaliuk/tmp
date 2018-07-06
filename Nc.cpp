#include "BestTanks.h"

Nc::Nc() {
	_win1 = NULL;
	_win2 = NULL;
	_win3 = NULL;
	_key = 0;
	_pause = FALSE;
}

int			Nc::getKey() const {
	return (_key);
}

_Bool		Nc::getPause() const {
	return (_pause);
}

void		Nc::setKey(int const key) {
	_key = key;
}

void		Nc::init() {
	if (!initscr())
		exit (0); // error
	if (!has_colors())
		exit (0); // error
	noecho();
	start_color();
	nodelay(stdscr, TRUE);
//	set_escdelay(25);
	keypad(stdscr, TRUE);
	curs_set(FALSE);

	init_color(COLOR_WHITE, 500, 500, 500);
	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_WHITE);
	init_pair(7, COLOR_GREEN, COLOR_WHITE);
	init_pair(8, COLOR_BLUE, COLOR_WHITE);
	init_pair(9, COLOR_RED, COLOR_WHITE);
	init_pair(10, COLOR_CYAN, COLOR_WHITE);
	init_pair(11, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(12, COLOR_WHITE, COLOR_BLACK);

	refresh();
	_win1 = newwin(HEIGHT_MAIN, WIDTH_MAIN, 0, 0);
	_win2 = newwin(HEIGHT_BATTLE, WIDTH_BATTLE, 1, 1);  //////
	_win3 = newwin(HEIGHT_INFO, WIDTH_INFO, 1, WIDTH_BATTLE);
	Nc::init_border();
	this->refreshWindows();
}

void		Nc::init_border() {
	attron(COLOR_PAIR(6));
	for (int i = 0; i < HEIGHT_MAIN; i++) {
		for (int j = 0; j <= WIDTH_MAIN; j++) //////////
			wprintw(_win1, "9"); ///////////////////////////
		wmove(_win1, i + 1, 0);
	}
	attroff(COLOR_PAIR(666));
}

void		Nc::refreshWindows() const {
	if (_win1)
		wrefresh(_win1);
	if (_win2)
		wrefresh(_win2);
	if (_win3)
		wrefresh(_win3);
}

void		Nc::menu(int & game) const {
	string str;

	str = "> 1 pl C"; // company
	mvwprintw(_win2, HEIGHT_BATTLE / 2 - 3, (WIDTH_BATTLE -  str.length()) / 2, str.c_str());
	str = "  2 pl C"; // company
	mvwprintw(_win2, HEIGHT_BATTLE / 2 - 1, (WIDTH_BATTLE -  str.length()) / 2, str.c_str());
	str = "  1 pl S"; // Survival
	mvwprintw(_win2, HEIGHT_BATTLE / 2 + 1, (WIDTH_BATTLE -  str.length()) / 2, str.c_str());
	str = "  2 pl S"; // Survival
	mvwprintw(_win2, HEIGHT_BATTLE / 2 + 3, (WIDTH_BATTLE -  str.length()) / 2, str.c_str());
	this->refreshWindows();
	game = 3; ////////////////////////////////
}

void		Nc::changePause() {
	_pause = !_pause;
}

void		Nc::wantPause() {
	string str;

	this->changePause();
	werase(_win2);
	str = "P A U S E";
	mvwprintw(_win2, HEIGHT_BATTLE / 2, (WIDTH_BATTLE -  str.length()) / 2, str.c_str());
	this->refreshWindows();
	while (TRUE) {
		this->setKey(getch());
		if (_key == 'p') {
			this->changePause();
			werase(_win2);
			this->refreshWindows();
			break ;
		}
		else if (_key == 'q') {
			this->changePause();
			this->wantQuit();
			break ;
		}
	}
}

void		Nc::wantQuit() {
	string str;

	this->changePause();
	werase(_win2);
	str = "Quit? Y / N";
	mvwprintw(_win2, HEIGHT_BATTLE / 2, (WIDTH_BATTLE -  str.length()) / 2, str.c_str());
	this->refreshWindows();
	while (TRUE) {
		this->setKey(getch());
		if (_key == 'y') {
			this->~Nc();
			exit(0);
		}
		else if (_key == 'n') {
			this->changePause();
			werase(_win2);
			this->refreshWindows();
			break ;
		}
	}
}

//void	Nc::printW2(char * map) const {
//	werase(_win2);
//	for (int i = 0; i < HEIGHT_BATTLE; i++) {
//		for (int j = 0; j < WIDTH_BATTLE; j++) {
//			if (map[i * WIDTH_BATTLE + j])
//				mvwprintw(_win2, i, j, "#");
//		}
//	}
////	mvwprintw(_win2, (int)xyway->getY(), (int)xyway->getX(), "#");
//	this->refreshWindows();
//}

void	Nc::printW2(vector<Texture *> & vecTexture, vector<Tank *> & vecTank, vector<Bullet *> & vecBullet) const {
	XYWay		* xyway;

	werase(_win2);

	for (int j = 0; j < vecTexture.size(); j++) {
		xyway = &vecTexture[j]->getXYWay();
		mvwprintw(_win2, xyway->getYRound(), xyway->getXRound(), "#");
	}
	xyway = &vecTank.front()->getXYWay();
	if (vecTank.front()->getType())
		mvwprintw(_win2, xyway->getYRound(), xyway->getXRound(), "=");
	else
		mvwprintw(_win2, xyway->getYRound(), xyway->getXRound(), "-");
	for (int j = 1; j < 3; j++) {
		xyway = &vecTank[j]->getXYWay();
		mvwprintw(_win2, xyway->getYRound(), xyway->getXRound(), "I");
	}
	for (int j = 3; j < vecTank.size(); j++) {
		xyway = &vecTank[j]->getXYWay();
		mvwprintw(_win2, xyway->getYRound(), xyway->getXRound(), "8");
	}
	for (int j = 0; j < vecBullet.size(); j++) {
		xyway = &vecBullet[j]->getXYWay();
		mvwprintw(_win2, xyway->getYRound(), xyway->getXRound(), "*");
	}
	refreshWindows();
}

Nc::~Nc() {
	delwin(_win1);
	delwin(_win2);
	delwin(_win3);
	endwin();
}
