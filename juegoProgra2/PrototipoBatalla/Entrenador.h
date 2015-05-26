#pragma once
#include "Pokemon.h"
#include <string>
class Entrenador
{
private:
	Pokemon *pikachucha;
	std::string nombre;
public:
	Entrenador(std::string nombre, Pokemon *p);
	~Entrenador();
};

