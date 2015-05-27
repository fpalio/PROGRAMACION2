#pragma once
#include "Entrenador.h"
using namespace System::Drawing;

class CEstado

{
protected:
	CEntrenador *Marco;
public:
	CEstado();
	virtual void Mover(Graphics ^g) = 0;
	virtual void Dibujar(Graphics ^g) = 0;
	
};

