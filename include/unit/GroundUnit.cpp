#include "GroundUnit.h"


vector<GroundUnit*> GroundUnit::objects;



GroundUnit::GroundUnit(Surface *parent,
					   double posx,
					   double posy,
					   double hitpoints) : Unit(parent,posx,posy,hitpoints)
{
	objects.push_back(this);

	jumpf =	0;

	bouncef =		0;
	frictionf =		0.1;
	airFrictionf =	0;
	enableFall =	true;
	noclip =		false;
}
GroundUnit::~GroundUnit()
{
	removeObject(*this,objects);
}



void GroundUnit::GroundUnit_idle()
{
	Unit_idle();

	if(!onGround())
		play("jump");
}
void GroundUnit::GroundUnit_walkLeft()
{
	Unit_goLeft();

	if(!onGround())
		play("jump");
}
void GroundUnit::GroundUnit_walkRight()
{
	Unit_goRight();

	if(!onGround())
		play("jump");
}
void GroundUnit::GroundUnit_jump()
{
	if(onGround())
	{
		play("jump");
		avel.y -= jumpf;
	}
}