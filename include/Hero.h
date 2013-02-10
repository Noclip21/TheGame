#ifndef HERO_H
#define HERO_H

#include "Unit.h"
#include "Axe.h"


class Hero : public Unit
{
public:

	static Hero *hero;
	
	Hero(Surface	*parent,
		double		posx = 0,
		double		posy = 0);
	~Hero();

private:

	bool _mousePressed;

	void idle();
	void walkLeft();
	void walkRight();
	void jump();
	void Hero_display();
};

#endif