#include "Hero.h"
#include "../world/World.h"

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


	_mousePressed = false;


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

	if(Event::keyDown(SDLK_SPACE)) GroundUnit_jump();
	World::debug->text(toStringi(jumpf));

	if(Event::mouseButtonDown(SDL_BUTTON_LEFT))
		_mousePressed = true;
	else
		if(_mousePressed)
		{
			_mousePressed = false;
			new Axe(parent(),pos.x,pos.y-32,25,ang(pos,parent()->mouse()));
		}

	if(Event::keyDown(SDLK_e))
	{
		implode();
		kill();
	}
}