#include "Item.h"


vector<Item*> Item::objects;

double Item::minDist = 10;



Item::Item(	char	*src,
			Surface *parent,
			double	posx,
			double	posy) : Sprite(	src,
									parent,
									posx,
									posy)
{



	objects.push_back(this);

	origin = vector2(16,32);

	addListener([this](){ Item_display(); });
}
Item::~Item()
{
	removeObject(*this,objects);
}



void Item::Item_display()
{
	if(alive(Hero::hero))
		if(dist(pos,Hero::hero->pos) <= minDist)
			kill();
}