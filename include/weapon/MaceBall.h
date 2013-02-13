#ifndef MACEBALL_H
#define MACEBALL_H

#include "../physics/Projectile.h"
#include "../unit/Unit.h"


class MaceBall : public Projectile
{
public:
	
	static vector<MaceBall*> objects;


	MaceBall(	Surface *parent =	NULL,
				double posx =		0,
				double posy =		0,
				double force =		0,
				double angle =		0);
	~MaceBall();

private:

	void MaceBall_display();
};

#endif;