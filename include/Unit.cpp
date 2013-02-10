#include "Unit.h"

vector<Unit*> Unit::objects;


Unit::Unit(	Surface *parent,
			double	posx,
			double	posy,
			float	bouncef,
			float	frictionf,
			bool	fall,
			bool	ghost,
			double	velocity,
			double	maxVelocity,
			double	jumpForce) : Physics(	parent,
											posx,
											posy,
											bouncef,
											frictionf,
											fall,
											ghost)
{
	objects.push_back(this);

	vel =		velocity;
	maxVel =	maxVelocity;
	jumpf =		jumpForce;

	addListener([this](){ Unit_display(); });
}
Unit::~Unit()
{
	removeObject(*this,objects);
}



void Unit::dashX(double fx)
{
	if(abs(avel.x + fx) <= maxVel)
		avel.x += fx;
	else
		if(fx > 0)	avel.x = maxVel;
		else		avel.x = -maxVel;
}
void Unit::dashY(double fy)
{
	if(abs(avel.y + fy) <= maxVel)
		avel.y += fy;
	else
		if(fy > 0)	avel.y = maxVel;
		else		avel.y = -maxVel;
}
void Unit::dash(vector2 force)
{
	dashX(force.x);
	dashY(force.y);
}

void Unit::dashRight()	{ dashX(vel);	}
void Unit::dashLeft()	{ dashX(-vel);	}
void Unit::dashUp()		{ dashY(-vel);	}
void Unit::dashDown()	{ dashY(vel);	}



void Unit::Unit_display()
{
	// code
}