#ifndef WOLF_H
#define WOLF_H

#include "GroundUnit.h"
#include "Hero.h"


class Wolf : public GroundUnit
{
public:

	static vector<Wolf*> objects;
	static int maxsight;
	static int attackRange;


	Wolf(	Surface *parent =	NULL,
			double	posx =		0,
			double	posy =		0);
	~Wolf();

private:

	bool _attacking;

	void Wolf_attack(Unit *target);

	void Wolf_display();
};

#endif