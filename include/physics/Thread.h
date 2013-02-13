#ifndef THREAD_H
#define THREAD_H

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
	void addNode(Physics *obj);

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
	vector<Physics*> _nodes;

	void Thread_display();
};

#endif