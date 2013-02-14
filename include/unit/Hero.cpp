#include "Hero.h"


Hero *Hero::hero;



Hero::Hero(Surface	*parent,
		   double	posx,
		   double	posy) : GroundUnit(	parent,
										posx,
										posy,
										100)
{
	if(hero) hero->kill();
	hero = this;


	vel =		1;
	maxVel =	10;
	jumpf =		20;


	_mousePressedL = false;
	_mousePressedR = false;

	_weapon = new Mace(this);


	char *idle[] = {"heroIdle.bmp"};
	char *walk[] = {"heroWalk1.bmp",
					"heroIdle.bmp",
					"heroWalk2.bmp",
					"heroIdle.bmp"};
	char *jump[] = {"heroWalk1.bmp"};

	addAnimation("idle",1,idle,1);
	addAnimation("walk",250,walk,4);
	addAnimation("jump",1,jump,1);


	addListener([this](){ Hero_display(); });
}
Hero::~Hero()
{
	hero = NULL;
}



void Hero::Hero_display()
{
	if(Event::keyDown(SDLK_a) || Event::keyDown(SDLK_d))
	{
		if(Event::keyDown(SDLK_a)) GroundUnit_walkLeft();
		if(Event::keyDown(SDLK_d)) GroundUnit_walkRight();
	}else
		GroundUnit_idle();

	if(Event::mouseButtonDown(SDL_BUTTON_LEFT))
		_mousePressedL = true;
	else
		if(_mousePressedL)
		{
			_mousePressedL = false;
			new Axe(parent(),pos.x,pos.y-32,30,ang(pos,parent()->mouse()));
		}

	if(Event::keyDown(SDLK_SPACE)) GroundUnit_jump();

	if(Event::mouseButtonDown(SDL_BUTTON_RIGHT))
		_mousePressedR = true;
	else
		if(_mousePressedR)
		{
			_mousePressedR = false;
			_weapon->shoot(ang(pos,parent()->mouse()));
		}

	if(Event::keyDown(SDLK_e))
	{
		implode();
		kill();
	}
}