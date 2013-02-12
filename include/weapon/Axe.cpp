#include "Axe.h"


vector<Axe*> Axe::objects;



Axe::Axe(Surface	*parent,
		 double		posx,
		 double		posy,
		 double		force,
		 float		angle) : Projectile(parent,
										posx,
										posy,
										force,
										angle)
{
	objects.push_back(this);

	setTexture("w_axe.bmp");

	origin = vector2(8,8);

	bounceFactor = 0.5;
	frictionFactor = 0.5;
	enableFall = true;
	noclip = false;

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
		kill();
		//_hitGround = true;
		//rotation = 0;
	}
	if(!_hitGround) rotation += 20;

	if(tragetsIntercepted.size() > 0)
		for(size_t i=0; i<tragetsIntercepted.size(); ++i)
			if(dynamic_cast<Unit*>(tragetsIntercepted[i]))
			{
				Unit *unit = ((Unit*)(tragetsIntercepted[i]));
				unit->unitdmg(10,4,oldPos());
			}
}