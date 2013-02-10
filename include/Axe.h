#ifndef AXE_H
#define AXE_H

#include "Projectile.h"


class Axe : public Projectile
{
public:

	static vector<Axe*> objects;


	Axe(Unit	*unit,
		double	force,
		float	angle);
	~Axe();

private:

	bool _hitGround;
	void Axe_display();
};

#endif