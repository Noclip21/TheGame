#include "Mace.h"


vector<Mace*> Mace::objects;
int Mace::_maxChains = 40;
int Mace::_time = 100;


Mace::Mace(Unit *unit)
{
	objects.push_back(this);

	_timer = 0;
	_unit = unit;
	_parent = unit->parent();

	addListener([this](){ Mace_display(); });
}
Mace::~Mace()
{
	deleteMaceThread();
	removeObject(*this,objects);
}



void Mace::shoot()
{
	_shooting = true;

	newMaceThread();
}
void Mace::retract()
{
	_shooting = false;
}


void Mace::deleteMaceThread()
{
	if(alive(_maceThread)) _maceThread->kill();
}
void Mace::newMaceThread()
{
	deleteMaceThread();
	_maceThread = new Thread();
}
void Mace::chainPush()
{
	if(_maceThread->size() < _maxChains)
	{
		Physics *chain = new Physics(_parent,_unit->pos.x,_unit->pos.y);
				if(_maceThread->size()%2 == 0)	chain->setTexture("maceChain1.bmp");
				else							chain->setTexture("maceChain2.bmp");

		_maceThread->addNode(chain);
	}else{
		Physics *mace = new Physics(_parent,_unit->pos.x,_unit->pos.y);
	}
}
void Mace::chainPop()
{
	if(_maceThread->begin())
	{
		_maceThread->begin()->kill();

		for(size_t i=1; i<_maceThread->size(); ++i)
			_maceThread->node(i)->pos = _maceThread->node(i-1)->pos;
	}
}




void Mace::Mace_display()
{
	if(SDL_GetTicks() - _timer >= _time)
	{
		if(_shooting)
		{
			chainPush();
		}else{
			chainPop();
		}
}