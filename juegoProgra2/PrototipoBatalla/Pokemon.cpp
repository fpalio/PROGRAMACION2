#include "Pokemon.h"



Pokemon::Pokemon(int att1, int def1, tipo t1)
{
	att = att1;
	def = def1;
	t = t1;
	isAlive = true;
	hp = 30;
}

int Pokemon::AttackPow()
{
	//hacer el random para effective super effective not very effective del att
	//att = blablabla
	return att;
}

void Pokemon::RecvDmg(int x)
{
	int dmg = x - def;
	hp -= dmg;
	if (hp <= 0) {
		hp = 0;
		isAlive = false;
	}
}
