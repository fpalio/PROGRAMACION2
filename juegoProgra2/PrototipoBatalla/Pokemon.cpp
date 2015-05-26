#include "Pokemon.h"



Pokemon::Pokemon(int att1, int def1, tipo t1)
{
	att = att1;
	def = def1;
	t = t1;
}

int Pokemon::AttackPow()
{
	//hacer el random para effective super effective not very effective del att
	//att = blablabla
	return att;
}

int Pokemon::RecvDmg(int x)
{
	//sigue vivo o no = 1 || 0        podemos cambiarlo por bool
	//sigue vivo = si
	int dmg = x - def;
	hp -= dmg;
	if (hp < 0) {
		hp = 0;
		//sigue vivo = no
	}
	//return siguevivo
	return 1;
}
