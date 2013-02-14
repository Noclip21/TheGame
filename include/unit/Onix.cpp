#include "Onix.h"


vector<Onix*> Onix::objects;



Onix::Onix(	Surface *parent,
			double posx,
			double posy) : Thread(parent,posx,posy,0,32)
{
	objects.push_back(this);

	int size = 30;
	int hp = 50;

	_head = new Unit(parent,posx,posy,hp);
			_head->setTexture("onixHead.bmp");
			_head->origin = vector2(32,32);
			_head->vel = 40;
			_head->maxVel = 40;
			addNodeBegin(_head);

	char *bodySpr[] =
	{"onixBody1.bmp",
	"onixBody2.bmp",
	"onixBody3.bmp"};

	for(int i=2; i<size; ++i)
	{
		Unit *body = new Unit(parent,posx,posy,hp);
				body->setTexture(bodySpr[rand()%3]);
				body->origin = vector2(32,32);
				body->addhitlines(vector2(0,0),vector2(64,64));
				body->addhitlines(vector2(0,64),vector2(64,0));
				addNodeEnd(body);
	}
	Unit *tail = new Unit(parent,posx,posy,hp);
			tail->setTexture("onixTail.bmp");
			tail->origin = vector2(32,32);
			tail->addhitlines(vector2(0,0),vector2(64,64));
			tail->addhitlines(vector2(0,64),vector2(64,0));
			addNodeEnd(tail);


	enableFall(true);


	addListener([this](){ Onix_display(); });
}
Onix::~Onix()
{
	removeObject(*this,objects);
}



void Onix::Onix_display()
{

	if(size() <= 1)
		kill();
	else{
		if(_head && Hero::hero)
			if(_head->pos.y > Physics::ground + 500)
			{
				double angle = ang(_head->pos,Hero::hero->pos);
				_head->dash(vector2(cos(angle)*_head->vel,sin(angle)*_head->vel));
			}
	}
}