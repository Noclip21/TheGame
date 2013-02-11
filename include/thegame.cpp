#include <gCore.h>

#include "World.h"


int main(int argc,char *argv[])
{
	Main window(1280,800,60,false,"The Game");

	Resource::cache("../res/hero/hero.wad");
	Resource::cache("../res/weapons/weapons.wad");
	Resource::cache("../res/pack.pak");
	Resource::cache("../res/cenario/background.wad");

	Object *obj = new Object();
		obj->addListener([obj]()
		{
			if(Event::keyDown(SDLK_ESCAPE))
				Main::RUNNING = false;
		});


	new World();


	window.display();
	return 0;
}