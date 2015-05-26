#pragma once
using namespace System::Drawing;
using namespace System::Windows::Forms;

enum ESTADO
{
	ARRIBA, ABAJO, IZQUIERDA,DERECHA
};

class CMarco
{
private: 
	int x;
	int y;
	int w;
	int h;
	int dx;
	int dy;
	int limX;
	int limY;
	ESTADO estado;
	int frame;
	bool dialogoV;
	

public:
	CMarco(int x, int y, int w, int h, int dx, int dy);
	~CMarco();
	void dibujar(Graphics^ g, Bitmap^ bmp);
	void mover(int limX, int limY, Keys key);
	int GetX();
	int GetY();
	int GetH();
	int GetW();
	void quieto(Keys key);
	void dibujarDialogo(Graphics^ g, Bitmap^bmpD,
	int xpantalla, int ypantalla,int wpantalla, int hpantalla);
	void hablar(Keys key);
};

