#include "Physics.h"


vector<Physics*> Physics::objects;
float			 Physics::gravity = 1;
double			 Physics::ground =	0;

bool Physics::onGround(){ return _onGround; }



Physics::Physics(Surface	*parent,
				 double		posx,
				 double		posy) : Animation(parent,posx,posy)
{
	objects.push_back(this);
	
	bouncef=		0;
	frictionf =		0;
	airFrictionf =	0;
	enableFall =	false;
	noclip =		true;
	
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
			pos.y =		ground;
			avel.x *=	(1-frictionf);

			if(abs(avel.y) >= 1) avel.y = -avel.y*bouncef;
			else				 avel.y = 0;
		}else
			_onGround = false;

	if(_onGround)
		avel = avel*(1-frictionf);
	else
		avel = avel*(1-airFrictionf);

	if(!_onGround && enableFall)
		avel.y += gravity;
}