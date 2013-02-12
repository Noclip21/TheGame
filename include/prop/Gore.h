#ifndef GORE_H
#define GORE_H

#include "../physics/Projectile.h"


#define GORE_BLOOD		0
#define GORE_BIGBLOOD	1
#define GORE_BITS		2


class Gore : public Projectile
{
public:

	static vector<Gore*> objects;
	static int maxgore;
	static int maxdecals;


	Gore(	int		type,
			Surface *parent,
			double	posx,
			double	posy,
			double	force,
			float	angle);
	~Gore();


	static void decal(	Surface *surface,
						double	posx,
						double	posy);

private:

	bool wasOnGround;
	
	static float _rotationf;


	static char *_decals[];
	static int _decalsNum;

	static char *_blood[];
	static int _bloodNum;

	static char *_bigblood[];
	static int _bigbloodNum;

	static char *_bits[];
	static int _bitsNum;

	static vector<Sprite*> _decalObjs;
	
	void Gore_blood_display();
	void Gore_bigblood_display();
	void Gore_bits_display();
};

#endif