#ifndef ONIX_H
#define ONIX_H

#include "../physics/Thread.h"
#include "Hero.h"


class Onix : public Thread
{
public:

	static vector<Onix*> objects;


	Onix(	Surface *parent = NULL,
			double posx = 0,
			double posy = 0);
	~Onix();

private:

	Unit *_head;
	void Onix_display();
};

#endif