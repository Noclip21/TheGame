#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Physics.h"
#include "Target.h"


class Projectile : public Physics
{
public:

	static vector<Projectile*> objects;

	vector<Target*> tragetsIntercepted;


	Projectile(	Surface	*parent =	NULL,
				double	posx =		0,
				double	posy =		0,
				double	force =		0,
				float	angle =		0);
	~Projectile();
	
private:

	void Projectile_display();
};

#endif