#ifndef PHYSICS_H
#define PHYSICS_H

#include <gCore.h>


class Physics : public Animation
{
public:

	static vector<Physics*> objects;


	static float gravity;
	static double ground;

	float	bouncef;
	float	frictionf;
	float	airFrictionf;

	bool	enableFall;
	bool	noclip;


	bool onGround();


	Physics(Surface *parent =	NULL,
			double	posx =		0,
			double	posy =		0);
	~Physics();

private:

	bool _onGround;

	void Physics_display();
};

#endif