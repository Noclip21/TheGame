#include "Target.h"


vector<Target*> Target::objects;

double Target::hp(){ return _hp; }

int Target::hlsize(){ return _hitlines.size(); };
vector2 Target::hlp1(int id)
{
	vector2 p;

	if(id >= 0 && id < _hitlines.size())
		p = _hitlines[id].first*scale+pos-origin;

	return p;
}
vector2 Target::hlp2(int id)
{
	vector2 p;

	if(id >= 0 && id < _hitlines.size())
		p = _hitlines[id].second*scale+pos-origin;

	return p;
}



Target::Target(Surface *parent,
			double		posx,
			double		posy,
			double		hitpoints) : Physics(	parent,
												posx,
												posy)
{
	objects.push_back(this);

	_hp = hitpoints;
}
Target::~Target()
{
	removeObject(*this,objects);
}



void Target::addhitlines(vector2 p1, vector2 p2)
{
	_hitlines.push_back(make_pair(p1,p2));
}
void Target::targetdmg(double dmg)
{
	_hp -= dmg;
	if(_hp <= 0) kill();
}
