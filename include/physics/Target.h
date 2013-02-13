#ifndef TARGET_H
#define TARGET_H

#include "Physics.h"


class Target : public Physics
{
public:

	static vector<Target*> objects;

	double hp();

	int hlsize();
	vector2 hlp1(int id);
	vector2 hlp2(int id);

	

	Target(	Surface *parent =	NULL,
			double	posx =		0,
			double	posy =		0,
			double hitpoints =	1);
	~Target();


	void addhitlines(vector2 p1,vector2 p2);
	void Target_dmg(double dmg);

private:

	double _hp;

	vector<pair<vector2,vector2>> _hitlines;
};

#endif