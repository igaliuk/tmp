#include "BestTanks.h"

Survival::Survival(Nc * nc, Controller * controller, int typeGame) : Game(nc, controller, typeGame) {}

//===================================================

Survival::~Survival() {}




//void	print2()
//{
//	XYWay *xyway;
//	std::ofstream	fout;
//	fout.open("111");
//	if (!fout.is_open())
//	{
//		std::cout << "BAD FILE" << std::endl;
//		std::exit(1);
//	}
//
//	fout << "Players" << std::endl;
//	for (int i = 0; i < _vecPlayer.size(); i++) {
//		xyway = &_vecPlayer[i]->getXYWay();
//		fout << "x " << xyway->getX() << std::endl;
//		fout << "y " << xyway->getY() << std::endl;
//		fout << "w " << xyway->getWay() << std::endl;
//		fout << "a " << _vecPlayer[i]->getAmmo() << std::endl;
//		fout << "p " << _vecPlayer[i]->getType() << std::endl;
//		fout << std::endl;
//	}
//	fout << "Bullets" << std::endl;
//	for (int i = 0; i < _vecBullet.size(); i++) {
//		xyway = &_vecBullet[i]->getXYWay();
//		fout << "x " << xyway->getX() << std::endl;
//		fout << "y " << xyway->getY() << std::endl;
//		fout << "w " << xyway->getWay() << std::endl;
//		fout << std::endl;
//	}
//
//	fout.close();
//}