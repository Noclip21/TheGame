#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Physics.h"
#include "Target.h"


class Projectile : public Physics
{
public:

	static vector<Projectile*> objects;

	vector<Target*> tragetsIntercepted;


	Projectile(	Surface	*parent,
				double	posx,
				double	posy,
				double	force,
				float	angle);
	~Projectile();
	
private:

	void Projectile_display();
};

#endif