#ifndef ITEM_H
#define ITEM_H

#include <gCore.h>

#include "Hero.h"


class Item : public Sprite
{
public:

	static vector<Item*> objects;

	static double minDist;

	Item(	char	*src,
			Surface *parent,
			double	posx = 0,
			double	posy = 0);
	~Item();
private:

	void Item_display();
};

#endif
