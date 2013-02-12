#include "Unit.h"


vector<Unit*> Unit::objects;


Unit::Unit(	Surface *parent,
			double	posx,
			double	posy,
			double	hitpoints) : Target(parent,
										posx,
										posy,
										hitpoints)
{
	objects.push_back(this);

	origin = vector2(32,64);

	vel =			0;
	maxVel =		0;
	jumpf =			0;
	attackf =		0;
	knockbackf =	0;

	_startHp = hitpoints;


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



void Unit::bleed(float angle)
{
	int maxBlood = rand()%4;
	for(int i=0; i<maxBlood; ++i)
	{
		float newAngle = angle + ((rand()%maxBlood)-maxBlood/2)*PI/8;
		new Gore(GORE_BLOOD,parent(),pos.x,pos.y-32,10,newAngle);
	}
}
void Unit::implode()
{
	float maxBlood = 6 + rand()%7;
	float initAngle = (rand()%90)*PI/180;
	for(int i=0; i<maxBlood; ++i)
	{
		float angle = initAngle + (1 + i)*((2*PI)/maxBlood);
		if(rand()%2 == 0)	new Gore(GORE_BIGBLOOD,parent(),pos.x,pos.y-32,20,angle);
		else				new Gore(GORE_BITS,parent(),pos.x,pos.y-32,20,angle);
	}
}
void Unit::unitdmg(double dmg,
				   double knockbackf,
				   vector2 origin)
{
	targetdmg(dmg);

	if(dmg > 0)
	{
		float angle = ang(origin,pos);
		avel.x += cos(angle)*knockbackf;
		avel.y += sin(angle)*knockbackf -5;

		bleed(angle);
		if(dmg >= _startHp) implode();
	}
}
void Unit::unitattck(Unit *unit)
{
	if(unit) unit->unitdmg(attackf,knockbackf,pos);
}



void Unit::Unit_display()
{
	// code
}