#include "Batalla.h"

#include <iostream>

Batalla::Batalla(Entrenador *p11, Entrenador *p21)
{
	p1 = p11;
	p2 = p21;
}


Batalla::~Batalla()
{
}

void Batalla::Pelear() {
	do {
		std::cout << "Elegir ataque o pasar (1 o 0)" << std::endl;
		char x = getchar();
		flushall();
		if (x == '1') {
			int att = p1->getPoke()->AttackPow(/*Pasar como parametro el ataque escogido*/); //ataque del p1
			p2->getPoke()->RecvDmg(att); //p2 recibe el daño de p1
			std::cout << "p1 ataca a p2 con " << att << " daño" << std::endl;
		}
		if (!p2->getPoke()->Alive()) continue; // no dejar que el p2 ataque si esta muerto
		int att2 = p2->getPoke()->AttackPow(); // ataque del p2
		p1->getPoke()->RecvDmg(att2); // p1 recibe daño del p2
		std::cout << "p2 ataca a p1 con " << att2 << " daño" << std::endl;
	} while (p1->getPoke()->Alive() && p2->getPoke()->Alive()); //mientras los dos esten vivos
	if (p1->getPoke()->Alive()) {
		std::cout << "el p1 ha ganado la batalla";
	}
	else {
		std::cout << "el p2 ha ganado la batalla";
	}

}
