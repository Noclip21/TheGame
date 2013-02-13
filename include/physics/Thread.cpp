#include "Thread.h"


vector<Thread*> Thread::objects;


Surface* Thread::parent(){ return _parent; }


int			Thread::size()			{ return _nodes.size();										}
Physics*	Thread::begin()			{ return (_nodes.size() > 0)?_nodes[0]:NULL;				}
Physics*	Thread::end()			{ return (_nodes.size() > 0)?_nodes[_nodes.size()-1]:NULL;	}
Physics*	Thread::node(size_t id) { return (id>=0 && id<_nodes.size())?_nodes[id]:NULL;		}


void Thread::bouncef(float n)
{
	for(size_t i=0; i<_nodes.size(); ++i)
		if(_nodes[i]) _nodes[i]->bouncef = n;
}
void Thread::frictionf(float n)
{
	for(size_t i=0; i<_nodes.size(); ++i)
		if(_nodes[i]) _nodes[i]->frictionf = n;
}
void Thread::airFrictionf(float n)
{
	for(size_t i=0; i<_nodes.size(); ++i)
		if(_nodes[i]) _nodes[i]->airFrictionf = n;
}
void Thread::enableFall(bool n)
{
	for(size_t i=0; i<_nodes.size(); ++i)
		if(_nodes[i]) _nodes[i]->enableFall = n;
}
void Thread::noclip(bool n)
{	for(size_t i=0; i<_nodes.size(); ++i)
		if(_nodes[i]) _nodes[i]->noclip = n;
}
void Thread::addNode(Physics *obj)
{
	_nodes.push_back(obj);
}



Thread::Thread(Surface *parent,
			   double	posx,
			   double	posy,
			   int		size,
			   double	nodeDistance)
{
	objects.push_back(this);

	for(int i=0; i<size; ++i)
		addNode(new Physics(parent,posx,posy));

	nodeDist = nodeDistance;

	addListener([this](){ Thread_display(); });
}
Thread::~Thread()
{
	for(size_t i=0; i<_nodes.size(); ++i)
		if(_nodes[i]) _nodes[i]->kill();

	removeObject(*this,objects);
}



void Thread::Thread_display()
{
	for(int i=1; i<_nodes.size(); ++i)
	{
		Physics *obj = _nodes[i];
		Physics *prev = node(i-1);
		if(alive(obj) && alive(prev))
		{
			double distance = dist(prev->pos,obj->pos);
			if(distance > nodeDist)
			{
				double angle = ang(prev->pos,obj->pos+obj->avel);
				obj->pos = prev->pos + vector2(cos(angle)*nodeDist,sin(angle)*nodeDist);
				obj->avel = vector2(0,0);
			}
		}else{
			if(!alive(obj))		removeObject(obj,_nodes);
			if(!alive(prev))	removeObject(prev,_nodes);
		}
	}
}