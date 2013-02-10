#ifndef PHYSICS_H
#define PHYSICS_H

#include <gCore.h>


class Physics : public Animation
{
public:

	static vector<Physics*> objects;


	static float gravity;
	static double ground;

	float bounceFactor;
	float frictionFactor;
	bool enableFall;
	bool noclip;


	bool onGround();


	Physics(Surface *parent,
			double	posx =		0,
			double	posy =		0,
			float	bouncef =	0,
			float	frictionf =	0,
			bool	fall =		false,
			bool	ghost =		true);
	~Physics();

private:

	bool _onGround;

	void Physics_display();
};

#endif