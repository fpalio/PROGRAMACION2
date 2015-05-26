#include <iostream>
#include "Batalla.h"

int main() {
	Pokemon *p1 = new Pokemon(10, 2, tipo::agua);
	Pokemon *p2 = new Pokemon(9, 3, tipo::trueno);
	Entrenador *ashketchupdelpueblopaleta = new Entrenador("Ash", p1);
	Entrenador *tetudo = new Entrenador("Enemy", p2);
	Batalla *b = new Batalla(ashketchupdelpueblopaleta, tetudo);
	b->Pelear();

	return 0;
}