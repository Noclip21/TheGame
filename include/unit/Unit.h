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
	double jumpf;
	double attackf;
	double knockbackf;


	Unit(	Surface *parent,
			double posx =		0,
			double posy =		0,
			double hitpoints =	100);
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
	void unitdmg(	double dmg,
					double knockbackf,
					vector2 origin);
	void unitattck(Unit *unit);

private:

	double _startHp;

	void Unit_display();
};

#endif