#include "Hero.h"


Hero *Hero::hero;



Hero::Hero(Surface	*parent,
		   double	posx,
		   double	posy) : Unit(	parent,
									posx,
									posy,
									0,
									0.1)
{
	if(hero) hero->kill();
	hero = this;

	char *idle[] = {"heroIdle.bmp"};
	char *walk[] = {"heroWalk1.bmp",
					"heroIdle.bmp",
					"heroWalk2.bmp",
					"heroIdle.bmp"};
	char *jump[] = {"heroWalk1.bmp"};

	addAnimation("idle",1,idle,1);
	addAnimation("walk",250,walk,4);
	addAnimation("jump",1,jump,1);

	origin = vector2(32,64);

	_mousePressed = false;

	addListener([this](){ Hero_display(); });
}
Hero::~Hero()
{
	hero = NULL;
}



void Hero::idle()
{
	if(onGround())	play("idle");
	else			play("jump");
}
void Hero::walkLeft()
{
	if(onGround())	play("walk");
	else			play("jump");

	scale.x = -abs(scale.x);

	dashLeft();
}
void Hero::walkRight()
{
	if(onGround())	play("walk");
	else			play("jump");

	scale.x = abs(scale.x);

	dashRight();
}
void Hero::jump()
{
	if(onGround()) 
	{
		play("jump");
		avel.y -= jumpf;
	}
}



void Hero::Hero_display()
{
	if(Event::keyDown(SDLK_a) || Event::keyDown(SDLK_d))
	{
		if(Event::keyDown(SDLK_a)) walkLeft();
		if(Event::keyDown(SDLK_d)) walkRight();
	}else
		idle();

	if(Event::keyDown(SDLK_SPACE)) jump();

	if(Event::mouseButtonDown(SDL_BUTTON_LEFT))
		_mousePressed = true;
	else
		if(_mousePressed)
		{
			_mousePressed = false;
			new Axe(this,30,ang(pos,parent()->mouse()));
		}
}