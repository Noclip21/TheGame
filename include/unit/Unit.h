#ifndef UNIT_H
#define UNIT_H

#include "../physics/Target.h"
#include "../prop//Gore.h"


class Unit : public Target
{
public:
	
	static vector<Unit*> objects;

	double vel;
	double maxVel;
	double attackf;
	double knockbackf;


	Unit(	Surface *parent =	NULL,
			double posx =		0,
			double posy =		0,
			double hitpoints =	1);
	~Unit();


	void dashX(double fx);
	void dashY(double fy);
	void dash(vector2 force);

	void dashRight();
	void dashLeft();
	void dashUp();
	void dashDown();

	void bleed(float angle);
	void implode();
	void Unit_dmg(	double dmg,
					double knockbackf,
					vector2 origin);

	void Unit_idle();
	void Unit_goLeft();
	void Unit_goRight();
	void Unit_attack(Unit *target);

private:

	double _startHp;
};

#endif