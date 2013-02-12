#ifndef AXE_H
#define AXE_H

#include "../physics/Projectile.h"
#include "../unit/Unit.h"


class Axe : public Projectile
{
public:

	static vector<Axe*> objects;


	Axe(Surface *parent,
		double	posx,
		double	posy,
		double	force,
		float	angle);
	~Axe();

private:

	bool _hitGround;
	void Axe_display();
};

#endif