#ifndef BESTTANKS_H
# define BESTTANKS_H

# include <iostream>
# include <string>
# include <cmath>
# include <vector>
# include <ncurses.h>
# include <stdbool.h>

using namespace std;



//////////////////////////////////////////////

# define HEIGHT_BATTLE			13
# define WIDTH_BATTLE			13

# define HEIGHT_INFO			HEIGHT_BATTLE
# define WIDTH_INFO				5

# define HEIGHT_MAIN			HEIGHT_BATTLE + 2
# define WIDTH_MAIN				WIDTH_BATTLE + WIDTH_INFO + 2

//////////////////////////////////////////////

# define UP						1
# define RIGHT					2
# define DOWN					3
# define LEFT					4

//////////////////////////////////////////////

# define START_POS_X_PL1		4.0
# define START_POS_Y_PL1		13.0
# define START_POS_X_PL2		8.0
# define START_POS_Y_PL2		13.0

# define START_POS_X_EN1		0.0
# define START_POS_Y_EN1		0.0
# define START_POS_X_EN2		6.0
# define START_POS_Y_EN2		0.0
# define START_POS_X_EN3		8.0
# define START_POS_Y_EN3		13.0

//////////////////////////////////////////////

# define SPEED_TANK1			1.0
# define SPEED_TANK2			2.0
# define SPEED_TANK3			3.0
# define SPEED_TANK4			4.0

# define SPEED_BULLET1			1.0
# define SPEED_BULLET2			2.0

//////////////////////////////////////////////

# define KEY_QUIT				'q'
# define KEY_PAUSE				'p'

# define KEY_PL1_UP				'w'
# define KEY_PL1_RIGHT			'd'
# define KEY_PL1_DOWN			's'
# define KEY_PL1_LEFT			'a'
# define KEY_PL1_FIRE			' '

# define KEY_PL2_UP				KEY_UP
# define KEY_PL2_RIGHT			KEY_RIGHT
# define KEY_PL2_DOWN			KEY_DOWN
# define KEY_PL2_LEFT			KEY_LEFT
# define KEY_PL2_FIRE			'0'

//////////////////////////////////////////////

# include "XYWay.hpp"
# include "Tank.hpp"
# include "Player.hpp"
# include "Enemy.hpp"
# include "Bullet.hpp"
# include "Texture.hpp"
# include "Controller.hpp"
# include "Nc.hpp"
# include "Battle.hpp"



#endif


//ITank *		Player::destroed() {
//	_lifes--;
//	if (_lifes > 0) {
//		Player *obj = new Player(this->getType());
//		obj->setLifes(this->getLifes());
//		obj->setScore(this->getScore());
//		this->~Player();
//		return (obj);
//	}
//	this->~Player();
//	return (NULL);
//}