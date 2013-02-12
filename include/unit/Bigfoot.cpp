#include "Bigfoot.h"


vector<Bigfoot*> Bigfoot::objects;

int Bigfoot::maxsight = 500;
int Bigfoot::attackRange = 10;



Bigfoot::Bigfoot(Surface *parent,
			double posx,
			double posy) : Unit(parent,
								posx,
								posy,
								100)
{
	objects.push_back(this);

	bounceFactor =		0;
	frictionFactor =	0.2;
	enableFall =		true;
	noclip =			false;


	vel =		1;
	maxVel =	5;
	jumpf =		0;
	attackf =	10;
	knockbackf = 5;


	addhitlines(vector2(20,0),vector2(40,64));
	addhitlines(vector2(20,64),vector2(40,0));


	_attacking = false;


	char *idle[] = {"bigfootIdle.bmp"};
	char *walk[] = {"bigfootWalk1.bmp",
					"bigfootIdle.bmp",
					"bigfootWalk2.bmp",
					"bigfootIdle.bmp"};
	char *jump[] = {"bigfootWalk1.bmp"};
	char *attk[] = {"bigfootAttack.bmp"};

	addAnimation("idle",1,idle,1);
	addAnimation("walk",250,walk,4);
	addAnimation("jump",1,walk,1);
	addAnimation("attack",1000,attk,1);


	addListener([this](){ Bigfoot_display(); });
}
Bigfoot::~Bigfoot() 
{
	removeObject(*this,objects);

	Projectile *body = new Projectile(parent(),pos.x,pos.y,15,(ang(oldPos(),pos)+ang(vector2(0,0),vector2(0,-1))/2));
	body->setTexture("bigfootDead.bmp");
	body->origin = vector2(32,64);
	body->bounceFactor =	0.5;
	body->frictionFactor =	0.2;
	body->enableFall =		true;
	body->noclip =			false;
	body->addListener([body]()
	{
		body->alpha -= 0.01;
		if(body->alpha <= 0)
			body->kill();
	});
}



void Bigfoot::idle()
{
	if(onGround())	play("idle");
	else			play("jump");
	avel = 0;
}
void Bigfoot::walkLeft()
{
	if(onGround())	play("walk");
	else			play("jump");

	scale.x = -abs(scale.x);

	dashLeft();
}
void Bigfoot::walkRight()
{
	if(onGround())	play("walk");
	else			play("jump");

	scale.x = abs(scale.x);

	dashRight();
}
void Bigfoot::attack(Unit *target)
{
	if(dist(pos,target->pos) <= attackRange && !_attacking)
	{
		_attacking = true;
		play("attack");
		callback([this](){ _attacking = false; });

		unitattck(target);
	}
}



void Bigfoot::Bigfoot_display()
{
	if(alive(Hero::hero))
	{
		Unit *hero = Hero::hero;

		if(dist(pos,hero->pos) <= maxsight)
		{
			attack(hero);

			if(!_attacking)
			{
				if(hero->pos.x < pos.x) walkLeft();
				if(hero->pos.x > pos.x) walkRight();
			}
		}else
			idle();
	}else
		idle();
}