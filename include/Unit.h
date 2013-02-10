#ifndef UNIT_H
#define UNIT_H

#include "Physics.h"


class Unit : public Physics
{
public:
	
	static vector<Unit*> objects;

	double vel;
	double maxVel;
	double jumpf;


	Unit(	Surface *parent,
			double posx =			0,
			double posy =			0,
			float bouncef =			0,
			float frictionf =		0.01,
			bool fall =				true,
			bool ghost =			false,
			double velocity =		1,
			double maxVelocity =	10,
			double jumpForce =		20);
	~Unit();


	void dashX(double fx);
	void dashY(double fy);
	void dash(vector2 force);

	void dashRight();
	void dashLeft();
	void dashUp();
	void dashDown();

private:

	void Unit_display();
};

#endif