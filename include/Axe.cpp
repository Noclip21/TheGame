#include "Axe.h"


vector<Axe*> Axe::objects;



Axe::Axe(Unit	*unit,
		double	force,
		float	angle) : Projectile(unit,
									force,
									angle)
{
	objects.push_back(this);

	setTexture("w_axe.bmp");

	origin = vector2(8,8);

	_hitGround = false;

	addListener([this](){ Axe_display(); });
}
Axe::~Axe()
{
	removeObject(*this,objects);
}




void Axe::Axe_display()
{
	if(onGround())
	{
		_hitGround = true;
		rotation = 0;
	}
	if(!_hitGround) rotation += 20;
}