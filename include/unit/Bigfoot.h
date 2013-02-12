#ifndef BIGFOOT_H
#define BIGFOOT_H

#include "Unit.h"
#include "Hero.h"


class Bigfoot : public Unit
{
public:

	static vector<Bigfoot*> objects;
	static int maxsight;
	static int attackRange;


	Bigfoot(Surface *parent,
			double posx,
			double posy);
	~Bigfoot();

private:

	bool _attacking;

	void idle();
	void walkLeft();
	void walkRight();
	void attack(Unit *target);

	void Bigfoot_display();
};

#endif