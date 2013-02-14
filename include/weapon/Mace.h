#ifndef MACE_H
#define MACE_H

#include "../physics/Thread.h"
#include "MaceBall.h"


class Mace : public Object
{
public:
	
	static vector<Mace*> objects;
	
	static int size;


	Mace(Unit *unit);
	~Mace();

	void shoot(double angle);

private:

	Unit *_unit;
	Thread *_thread;
	MaceBall *_ball;


	void Mace_display();
};

#endif