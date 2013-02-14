#ifndef HERO_H
#define HERO_H

#include "GroundUnit.h"
#include "../weapon/Axe.h"
#include "../weapon/Mace.h"


class Hero : public GroundUnit
{
public:

	static Hero *hero;
	

	Hero(Surface	*parent,
		double		posx = 0,
		double		posy = 0);
	~Hero();

private:

	bool _mousePressedL;
	bool _mousePressedR;

	Mace *_weapon;


	void Hero_display();
};

#endif