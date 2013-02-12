#include <gCore.h>

#include "world/World.h"



int main(int argc,char *argv[])
{
	putenv("SDL_VIDEO_CENTERED=1");

	Resource::cache("../res/pack1.pak");
	{
		Main precacheWindow(256,256,60,false,"The Game");
		Screen *screen = new Screen(NULL,0,0,512,512);
		new Sprite("purple256.bmp",screen);
		new Sprite("logo256.bmp",screen);
		Text *text = new Text("Loading...",screen,0,0,18);
		text->addListener([](){
			Resource::cache("../res/pack2.pak");
			Main::RUNNING = false;
		});
		precacheWindow.display();
	}

	{
		Main window(1280,800,60,true,"The Game");
		new World();
		Object *obj = new Object();
			obj->addListener([obj]()
			{
				if(Event::keyDown(SDLK_ESCAPE))
					Main::RUNNING = false;
			});
		window.display();
	}

	Resource::dump("../res/pack1.pak");
	Resource::dump("../res/pack2.pak");
	return 0;
}