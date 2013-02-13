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
	attackf =		0;
	knockbackf =	0;

	bouncef =		0;
	frictionf =		0;
	airFrictionf =	0;
	enableFall =	false;
	noclip =		true;

	_startHp = hitpoints;
}
Unit::~Unit()
{
	removeObject(*this,objects);
}



void Unit::dashX(double fx)
{
	if(fx > 0)
		if(avel.x + fx <= maxVel)
			avel.x += fx;
		else
			if(avel.x <= maxVel)
				avel.x = maxVel;
	if(fx < 0)
		if(avel.x + fx >= -maxVel)
			avel.x += fx;
		else
			if(avel.x >= -maxVel)
				avel.x = -maxVel;
}
void Unit::dashY(double fy)
{
	if(fy > 0)
		if(avel.y + fy <= maxVel)
			avel.y += fy;
		else
			if(avel.y <= maxVel)
				avel.y = maxVel;
	if(fy < 0)
		if(avel.y + fy >= -maxVel)
			avel.y += fy;
		else
			if(avel.y >= -maxVel)
				avel.y = -maxVel;
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
void Unit::Unit_dmg(double dmg,
				   double knockbackf,
				   vector2 origin)
{
	Target_dmg(dmg);

	if(dmg > 0)
	{
		float angle = ang(origin,pos);
		avel.x += cos(angle)*knockbackf;
		avel.y += sin(angle)*knockbackf -5;

		bleed(angle);
		if(dmg >= _startHp) implode();
	}
}



void Unit::Unit_idle()
{
	play("idle");

	avel = 0;
}
void Unit::Unit_goLeft()
{
	play("walk");

	scale.x = -abs(scale.x);

	dashLeft();
}
void Unit::Unit_goRight()
{
	play("walk");

	scale.x = abs(scale.x);

	dashRight();
}
void Unit::Unit_attack(Unit *target)
{
	play("attack");
	
	if(target) target->Unit_dmg(attackf,knockbackf,pos);
}