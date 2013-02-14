#include "Mace.h"


vector<Mace*>	Mace::objects;
int				Mace::size = 300;



Mace::Mace(Unit *unit)
{
	objects.push_back(this);

	
	_unit = unit;


	addListener([this](){ Mace_display(); });
}
Mace::~Mace()
{
	if(_thread) _thread->kill();

	removeObject(*this,objects);
}



void Mace::shoot(double angle)
{
	if(_thread)
		_thread->kill();

	if(_unit)
	{
		_thread = new Thread(_unit->parent(),_unit->pos.x,_unit->pos.y,(size/8)+1,8);
		_thread->enableFall(true);
		_thread->noclip(false);
		if(_thread->begin())
		{
			_ball = new MaceBall(_unit->parent(),_unit->pos.x,_unit->pos.y,25,angle);
			_thread->addNodeBegin(_ball);
		}
		for(int i=1; i<_thread->size(); ++i)
		{
			Physics *obj = _thread->node(i);
			if(i%2 == 0) obj->setTexture("maceChain1.bmp");
			else		 obj->setTexture("maceChain2.bmp");
			obj->origin = vector2(8,8);
		}
	}
}



void Mace::Mace_display()
{
	if(_thread && _unit)
	{
		if(_ball)
		{
			double distance = dist(_unit->pos,_ball->pos);
			double maxDistance = size*8;
			if(distance > maxDistance)
			{
				double angle = ang(_unit->pos,_ball->pos);
				_ball->pos = _unit->pos + vector2(cos(angle)*maxDistance,sin(angle)*maxDistance);
				_ball->avel = _unit->avel - vector2(cos(angle)*(distance-maxDistance),sin(angle)*(distance-maxDistance));
			}
		}
		/*for(int i=1; i<_thread->size(); ++i)
		{
			Physics *obj = _thread->node(i);
			Physics *prev = _thread->node(i-1);
			if(obj && prev)
				obj->rotation = ang(prev->pos,obj->pos)*180/PI;
		}*/
	}
}