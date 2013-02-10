#include "Physics.h"


vector<Physics*> Physics::objects;
float			 Physics::gravity = 1;
double			 Physics::ground =	0;

bool Physics::onGround(){ return _onGround; }



Physics::Physics(Surface	*parent,
				 double		posx,
				 double		posy,
				 float		bouncef,
				 float		frictionf,
				 bool		fall,
				 bool		ghost) : Animation(parent,posx,posy)
{
	objects.push_back(this);

	bounceFactor =	 bouncef;
	frictionFactor = frictionf;
	enableFall =	 fall;
	noclip =		 ghost;
	
	_onGround =	false;

	addListener([this](){ Physics_display(); });
}
Physics::~Physics()
{
	removeObject(*this,objects);
}



void Physics::Physics_display()
{
	if(noclip)
		_onGround = false;
	else
		if(pos.y + avel.y >= ground)
		{
			_onGround = true;
			pos.y = ground;
			avel.x *= (1-frictionFactor);
			avel.y = -avel.y*bounceFactor;
		}else
			_onGround = false;

	if(!_onGround && enableFall)
		avel.y += gravity;
}