#include "Projectile.h"


vector<Projectile*> Projectile::objects;



Projectile::Projectile(	Surface	*parent,
						double	posx,
						double	posy,
						double	force,
						float	angle) : Physics(	parent,
													posx,
													posy)
{
	objects.push_back(this);
	

	airFrictionf =	0;
	enableFall =	true;
	noclip =		false;


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
	while(tragetsIntercepted.size() > 0)
	tragetsIntercepted.erase(tragetsIntercepted.begin());

	for(size_t i = 0; i<Target::objects.size(); ++i)
	{
		Target *obj = Target::objects[i];
		if(obj)
			for(size_t j=0; j< obj->hlsize(); ++j)
				if(segIntersec(pos,oldPos(),obj->hlp1(j),obj->hlp2(j)))
				{
					tragetsIntercepted.push_back(obj);
					break;
				}
	}
}