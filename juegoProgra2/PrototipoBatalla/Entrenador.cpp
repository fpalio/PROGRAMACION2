#include "Entrenador.h"



Entrenador::Entrenador(std::string nombre1,  Pokemon *p)
{
	nombre = nombre1;
	pikachucha = p;
}

Pokemon * Entrenador::getPoke()
{
	return pikachucha;
}


Entrenador::~Entrenador()
{
}
