#include "World.h"


World	*World::world;
Surface	*World::gui;
Surface *World::surf;

Text *World::debug;



World::World() : Screen(NULL,0,0,Main::width(),Main::height())
{
	if(world) world->kill();
	world = this;

	gui =	new Surface(this);
	surf =	new Surface(this);

	debug = new Text("--",gui);


	Hero *hero = new Hero(surf,0,0);
	
	new Item("v_axe.bmp",surf,100);
	new Item("v_axe.bmp",surf,200);
	new Item("v_axe.bmp",surf,300);

	
	cam(surf,hero);
}
World::~World()
{
	// code
}
