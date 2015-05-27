  #pragma once
#pragma once
#include "Marco.h"
enum STATE {
	overworld,
	batalla
};

class CControlador
{
private:
	int x;
	int y;
	CMarco* marco;
	STATE estado;

public:
	CControlador(int x, int y, CMarco* marco);
	~CControlador();
	void DibujarPersonaje(Graphics^ g, Bitmap^ bmp);
	void MoverMarco(Keys key, int limX, int limY);
	void dibujarFondo(Graphics^ g, Bitmap^ bmp, Bitmap^bmpM, Bitmap^ bmpD, int wfondo, int hfondo);
	void QuietoMarco(Keys key); 
	void dibujarDialogo(Graphics^ g, Bitmap^bmpD, int xpantalla, int ypantalla, int wpantalla, int hpantalla);
	void marcoHablar(Keys key);

};

