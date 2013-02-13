#include "Wolf.h"


vector<Wolf*> Wolf::objects;
int Wolf::maxsight = 500;
int Wolf::attackRange = 10;



Wolf::Wolf(Surface *parent,
			double	posx,
			double	posy) : GroundUnit(	parent,
										posx,
										posy,
										50)
{
	objects.push_back(this);


	vel =		2;
	maxVel =	8;
	jumpf =		20;
	attackf =	20;
	knockbackf = 10;


	addhitlines(vector2(20,0),vector2(40,64));
	addhitlines(vector2(20,64),vector2(40,0));


	_attacking = false;


	char *idle[] = {"wolfIdle.bmp"};
	char *walk[] = {"wolfWalk1.bmp",
					"wolfIdle.bmp",
					"wolfWalk2.bmp",
					"wolfIdle.bmp"};
	char *jump[] = {"wolfWalk1.bmp"};
	char *attk[] = {"wolfAttack.bmp"};

	addAnimation("idle",1,idle,1);
	addAnimation("walk",100,walk,4);
	addAnimation("jump",1,walk,1);
	addAnimation("attack",500,attk,1);


	addListener([this](){ Wolf_display(); });
}
Wolf::~Wolf()
{
	removeObject(*this,objects);

	Projectile *body = new Projectile(parent(),pos.x,pos.y,15,(ang(oldPos(),pos)+ang(vector2(0,0),vector2(0,-1))/2));
	body->setTexture("wolfDead.bmp");
	body->origin = vector2(32,64);
	body->bouncef =		0.5;
	body->frictionf =	0.2;
	body->enableFall =	true;
	body->noclip =		false;
	body->addListener([body]()
	{
		body->alpha -= 0.01;
		if(body->alpha <= 0)
			body->kill();
	});
}



void Wolf::Wolf_attack(Unit *target)
{
	if(dist(pos,target->pos) <= attackRange && !_attacking)
	{
		Unit_attack(target);

		_attacking = true;
		callback([this](){ _attacking = false; });
	}else{
		if(dist(pos,target->pos) < jumpf*10 && !target->onGround())
			GroundUnit_jump();
	}
}



void Wolf::Wolf_display()
{
	if(alive(Hero::hero))
	{
		Unit *hero = Hero::hero;

		if(dist(pos,hero->pos) <= maxsight)
		{
			Wolf_attack(hero);

			if(!_attacking && onGround())
			{
				if(hero->pos.x < pos.x) GroundUnit_walkLeft();
				if(hero->pos.x > pos.x) GroundUnit_walkRight();
			}
		}else
			GroundUnit_idle();
	}else
		GroundUnit_idle();
}