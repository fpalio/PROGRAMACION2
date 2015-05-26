#pragma once
#include "Entrenador.h"
class Batalla
{
private:
	Entrenador *p1, *p2;
public:
	Batalla(Entrenador *p1, Entrenador *p2);
	~Batalla();
	void Pelear();
};

