#ifndef GROUNDUNIT_H
#define GROUNDUNIT_H

#include "Unit.h"


class GroundUnit : public Unit
{
public:
	
	static vector<GroundUnit*> objects;

	double jumpf;


	GroundUnit(	Surface *parent =	NULL,
				double posx =		0,
				double posy =		0,
				double hitpoints = 1);
	~GroundUnit();

	void GroundUnit_idle();
	void GroundUnit_walkLeft();
	void GroundUnit_walkRight();
	void GroundUnit_jump();

private:
};

#endif