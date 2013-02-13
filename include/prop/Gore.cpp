#include "Gore.h"


vector<Gore*>	Gore::objects;
int				Gore::maxgore =		30;
int				Gore::maxdecals =	30;

char*			Gore::_decals[] =	{"{blood1.bmp","{blood2.bmp","{blood3.bmp"};
int				Gore::_decalsNum =	3;

char*			Gore::_blood[] =	{"blood1.bmp","blood2.bmp","blood3.bmp"};
int				Gore::_bloodNum =	3;

char*			Gore::_bigblood[] =	{"bigblood1.bmp","bigblood2.bmp","bigblood3.bmp"};
int				Gore::_bigbloodNum = 3;

char*			Gore::_bits[] =		{"bone1.bmp","bone2.bmp","bone3.bmp","gut1.bmp","gut2.bmp","gut3.bmp"};
int				Gore::_bitsNum =	6;

vector<Sprite*> Gore::_decalObjs;
float			Gore::_rotationf = 25;


Gore::Gore(int		type,
		   Surface	*parent,
		   double	posx,
		   double	posy,
		   double	force,
		   float	angle) : Projectile(parent,
										posx,
										posy,
										force,
										angle)

{
	objects.push_back(this);
	if(objects.size() > maxgore)
		for(int i=0; i<objects.size()-maxgore; ++i)
			if(objects[i]) objects[i]->kill();

	origin = vector2(16,16);

	
	avelrot =		_rotationf;
	wasOnGround =	false;

	enableFall =	true;
	noclip =		false;
	airFrictionf =	0;
	switch(type)
	{
		case(GORE_BLOOD):{
			bouncef =	0;
			frictionf =	0;

			setTexture(_blood[rand()%_bloodNum]);

			addListener([this](){ Gore_blood_display(); });

			break;
		}
		case(GORE_BIGBLOOD):{
			bouncef =	0;
			frictionf =	0;

			setTexture(_bigblood[rand()%_bigbloodNum]);

			addListener([this](){ Gore_bigblood_display(); });

			break;
		}
		case(GORE_BITS):{
			bouncef =	0.5;
			frictionf =	0.5;

			setTexture(_bits[rand()%_bitsNum]);

			addListener([this](){ Gore_bits_display(); });

			break;
		}
	}
}
Gore::~Gore()
{
	removeObject(*this,objects);
}



void Gore::decal(	Surface *surface,
					double	posx,
					double	posy)
{
	Sprite *decal = new Sprite(_decals[rand()%_decalsNum],surface,posx,posy);
			decal->origin = vector2(16,16);

	_decalObjs.push_back(decal);
	while(_decalObjs.size() > maxdecals)
	{
		_decalObjs[0]->kill();
		_decalObjs.erase(_decalObjs.begin());
	}
}



void Gore::Gore_blood_display()
{
	if(onGround())
	{
		if(rand()%10 <= 1) decal(parent(),pos.x,pos.y);
		kill();
	}
}

void Gore::Gore_bigblood_display()
{
	if(onGround())
	{
		decal(parent(),pos.x,pos.y);
		kill();
	}
}

void Gore::Gore_bits_display()
{
	if(onGround())
	{
		if(!wasOnGround) decal(parent(),pos.x,pos.y);
		avelrot = avel.x;
	}

	wasOnGround = onGround();
}