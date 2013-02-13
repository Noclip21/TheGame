#ifndef BIGFOOT_H
#define BIGFOOT_H

#include "GroundUnit.h"
#include "Hero.h"


class Bigfoot : public GroundUnit
{
public:

	static vector<Bigfoot*> objects;
	static int maxsight;
	static int attackRange;


	Bigfoot(Surface *parent,
			double posx,
			double posy);
	~Bigfoot();


	void Bigfoot_attack(Unit *target);

private:

	bool _attacking;

	void Bigfoot_display();
};

#endif