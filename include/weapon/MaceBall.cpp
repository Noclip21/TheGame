#include "MaceBall.h"


vector<MaceBall*> MaceBall::objects;



MaceBall::MaceBall(Surface *parent,
				   double posx,
				   double posy,
				   double force,
				   double angle) : Projectile(parent,posx,posy,force,angle)
{
	objects.push_back(this);

	setTexture("maceBall.bmp");
	origin = vector2(32,32);

	bouncef =	0.2;
	frictionf = 0.5;
}
MaceBall::~MaceBall()
{
	removeObject(*this,objects);
}



void MaceBall::MaceBall_display()
{
	if(tragetsIntercepted.size() > 0)
		for(size_t i=0; i<tragetsIntercepted.size(); ++i)
			if(dynamic_cast<Unit*>(tragetsIntercepted[i]))
			{
				Unit *unit = ((Unit*)(tragetsIntercepted[i]));
				unit->Unit_dmg(50,10,oldPos());
			}
}