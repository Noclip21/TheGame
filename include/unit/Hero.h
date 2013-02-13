#ifndef HERO_H
#define HERO_H

#include "GroundUnit.h"
#include "../weapon/Axe.h"


class Hero : public GroundUnit
{
public:

	static Hero *hero;
	

	Hero(Surface	*parent,
		double		posx = 0,
		double		posy = 0);
	~Hero();

private:

	bool _mousePressed;

	void Hero_display();
};

#endif