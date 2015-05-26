#pragma once

enum tipo {
	agua, fuego, trueno
};

class Pokemon
{
private:
	int att, def, hp, exp, lvl;
	tipo t;
	bool isAlive;
public:
	Pokemon(int att1, int def1, tipo t1);
	int AttackPow();
	void RecvDmg(int x);
	int getAtt() { return att; }
	int getDef() { return def; }
	int getHP() { return hp; }
	bool Alive() { return isAlive; }

};

