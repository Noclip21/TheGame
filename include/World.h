#ifndef WORLD_H
#define WORLD_H

#include <gCore.h>

#include "Hero.h"
#include "Item.h"

class World : public Screen
{
public:

	static World	*world;
	static Surface	*gui;
	static Surface	*surf;

	static Text		*debug;

	World();
	~World();

private:

	Surface *bg;
	Surface *fg;
	void createBackground();
	void createForeground();

	void World_display();
};

#endif