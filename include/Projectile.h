#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Physics.h"
#include "Unit.h"


class Projectile : public Physics
{
public:

	static vector<Projectile*> objects;


	Projectile(	Unit	*unit,
				double	force,
				float	angle);
	~Projectile();
	
private:

	void Projectile_display();
};

#endif