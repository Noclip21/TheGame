#include "Projectile.h"


vector<Projectile*> Projectile::objects;



Projectile::Projectile(	Unit	*unit,
						double	force,
						float	angle) : Physics(	unit->parent(),
													unit->pos.x,
													unit->pos.y,
													0.5,
													0.5,
													true,
													false)
{
	objects.push_back(this);

	avel.x = cos(angle)*force;
	avel.y = sin(angle)*force;

	addListener([this](){ Projectile_display(); });
}
Projectile::~Projectile()
{
	removeObject(*this,objects);
}



void Projectile::Projectile_display()
{
	// code
}