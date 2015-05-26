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
	std::cout << "Elegir ataque o pasar (1 o 0)";
	char x = getchar();
	if(x == '1')
}
