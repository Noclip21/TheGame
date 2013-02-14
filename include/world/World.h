#ifndef WORLD_H
#define WORLD_H

#include <gCore.h>

#include "../unit/Hero.h"
#include "../item/Item.h"
#include "../unit/Bigfoot.h"
#include "../unit/Wolf.h"
#include "../unit/Onix.h"


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
	
	static int _restartTime;
	int	_restartTimer;

	Audio *audio;
	void createBackground();
	void createForeground();

	void World_display();
};

#endif