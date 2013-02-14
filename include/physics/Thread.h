#ifndef THREAD_H
#define THREAD_H

#include <deque>

#include "Physics.h"


class Thread : public Object
{
public:

	static vector<Thread*> objects;


	double nodeDist;


	Surface* parent();

	int size();
	Physics* begin();
	Physics* end();
	Physics* node(size_t id);
	void addNodeBegin(Physics *obj);
	void addNodeEnd(Physics *obj);

	void bouncef(float n);
	void frictionf(float n);
	void airFrictionf(float n);
	void enableFall(bool n);
	void noclip(bool n);


	Thread(	Surface *parent =		NULL,
			double posx =			0,
			double posy =			0,
			int size =				0,
			double nodeDistance =	0);
	~Thread();

private:

	Surface* _parent;
	deque<Physics*> _nodes;


	void ThreadRemoveOject(Object *obj);
	void Thread_display();
};

#endif