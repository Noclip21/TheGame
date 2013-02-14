#include "World.h"


World	*World::world;
Surface	*World::gui;
Surface *World::surf;

Text *World::debug;

int World::_restartTime = 2000;



World::World() : Screen(NULL,0,0,Main::width(),Main::height())
{
	if(world) world->kill();
	world = this;

	createBackground();
	createForeground();

	gui =	new Surface(this);
	surf =	new Surface(this);

	debug = new Text("mover [A,D]    pular [SPACE]    atacar [MOUSE1]    suicidio [E]",gui,0,0,24);

	_restartTimer = -1;

	audio = new Audio("Brodyquest.wav",true);
	audio->play();


	Hero *hero = new Hero(surf,7000,-100);
	cam(surf,hero);


	new Item("v_axe.bmp",surf,100);
	new Item("v_axe.bmp",surf,200);
	new Item("v_axe.bmp",surf,300);

	addListener([this](){ World_display(); });
}
World::~World()
{
	//audio->kill();
}



void World::createBackground()
{
	bg = new Surface(this);

	char *textures[] = {"bg_01aa.bmp","bg_02aa.bmp","bg_03aa.bmp","bg_04aa.bmp"};

	for(int x=0; x<4; ++x)
			new Sprite(textures[x],bg,x*2048,-1024);
}
void World::createForeground()
{
	fg = new Surface(this);

	char *textures[] = {"fg_01aa.bmp","fg_02aa.bmp","fg_03aa.bmp"};

	for(int x=0; x<16; ++x)
			new Sprite(textures[rand()%3],fg,x*1024,-800);
}



void World::World_display()
{
	bg->pos = surf->pos*0.5;
	fg->pos = surf->pos;
	
	if(alive(Hero::hero))
	{
		if(Hero::hero->pos.y>-200)
			cam()->target(vector2(Hero::hero->pos.x,-200));
		else
			cam()->target(Hero::hero);

		
		if(Bigfoot::objects.size() < 3)
			new Bigfoot(surf,Hero::hero->pos.x+(rand()%2000)-1000,Physics::ground);

		if(Wolf::objects.size() < 5)
			new Wolf(surf,Hero::hero->pos.x+(rand()%2000)-1000,Physics::ground);

		if(Onix::objects.size() < 1)
			new Onix(surf,Hero::hero->pos.x+(rand()%2000)-1000,Physics::ground);


	}else{
		if(_restartTimer < 0) _restartTimer = SDL_GetTicks();
		if(SDL_GetTicks() - _restartTimer >= _restartTime)
			new World();
	}
}
