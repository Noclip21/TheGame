#ifndef MACE_H
#define MACE_H

#include "../physics/Thread.h"
#include "MaceBall.h"


class Mace : public Object
{
public:
	
	static vector<Mace*> objects;


	Mace(Unit *unit);
	~Mace();

	void shoot();
	void retract();

private:

	static int _maxChains;
	static int _time;
	int _timer;

	Unit *_unit;
	Surface *_parent;

	Thread *_maceThread;
	Physics *_maceBall;

	bool _shooting;

	void deleteMaceThread();
	void newMaceThread();

	void chainPush();
	void chainPop();

	void Mace_display()
};

#endif