#include "Pokemon.h"

//la clase de pokemon mayomente va a ser gets y sets ya que solo tiene que 
// contener informacion del pokemon y nada mas dentro de batalla
// c usan a los dos pokemones en la batallla para hacer cosas como 
// attaque o reciver daño 

Pokemon::Pokemon(int att1, int def1, tipo t1)
{
	att = att1;
	hp = 100;
	exp = 0;
	lvl = 10;
	def = def1;
	t = t1;
}
//el attaque va a estar dentro de ontra clase , ya que el metodo necesita recivir 
// dos pokemones para comparar que tipos son y el attaque realizado
// de ahi c puede ver si es super effective 
int Pokemon::AttackPow()
{
	
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
