#ifndef BESTTANKS_H
# define BESTTANKS_H

# include <iostream>
# include <string>
# include <cmath>
# include <vector>
# include <ncurses.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h> //////////////

using namespace std;

int			roundfTank(float const f);

//////////////////////////////////////////////

# define PLAYER1				1
# define PLAYER2				2
# define EAGLE					3
# define ENEMY1					4
# define ENEMY2					5
# define ENEMY3					6
# define ENEMY4					7

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

# define STEP_TIME				5
# define DELAY_RESP				2000
# define RESP_TIME				200000
# define FREEZE_TIME			10000

//////////////////////////////////////////////

# define NUM_OF_ENEMY_GAME		20
# define NUM_OF_ENEMY_FIELD		7

//////////////////////////////////////////////

# define START_POS_X_PL1		4.0f
# define START_POS_Y_PL1		12.0f
# define START_POS_X_PL2		8.0f
# define START_POS_Y_PL2		12.0f

# define START_POS_X_EN1		0.0f
# define START_POS_Y_EN1		0.0f
# define START_POS_X_EN2		6.0f
# define START_POS_Y_EN2		0.0f
# define START_POS_X_EN3		12.0f
# define START_POS_Y_EN3		0.0f

# define START_POS_X_EA			6.0f
# define START_POS_Y_EA			12.0f

//////////////////////////////////////////////

# define SPEED_TANK1			0.2f
# define SPEED_TANK2			0.3f
# define SPEED_TANK3			0.0001f

# define SPEED_BULLET1			0.001f
# define SPEED_BULLET2			0.002f

//////////////////////////////////////////////

# define POINTS_BONUS			500
# define POINTS_ENEMY1			100
# define POINTS_ENEMY2			200
# define POINTS_ENEMY3			300
# define POINTS_ENEMY4			400

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
# include "Eagle.hpp"
# include "Bullet.hpp"
# include "Texture.hpp"
# include "Bonus.hpp"
# include "Bonus1.hpp"
# include "Bonus2.hpp"
# include "Bonus3.hpp"
# include "Bonus4.hpp"
# include "Bonus5.hpp"
# include "Bonus6.hpp"
# include "Controller.hpp"
# include "Nc.hpp"
# include "Game.hpp"
# include "Survival.hpp"
# include "Menu.hpp"



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
