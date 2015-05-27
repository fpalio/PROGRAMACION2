#include "stdafx.h"
#include "Controlador.h"


CControlador::CControlador(int x, int y, CMarco* marco)
{
	this->x = x;
	this->y = y;
	this->marco = marco;
	estado = STATE::batalla;
}

CControlador::~CControlador()
{
}

void CControlador::DibujarPersonaje(Graphics^ g, Bitmap^ bmp)
{
	marco->dibujar(g, bmp);
}

void CControlador::MoverMarco(Keys key, int limX, int limY)
{
	marco->mover(limX, limY, key);
}

void CControlador::dibujarFondo(Graphics^ g, Bitmap^ bmp, Bitmap^bmpM, Bitmap^ bmpD,
	int wfondo, int hfondo,Label^ dialogo)
{
	Bitmap^ bmFondo = gcnew Bitmap(wfondo, hfondo);
	Graphics^ gFondo = Graphics::FromImage(bmFondo); // de donde saca la imagen del fondo?

	// el Graphics g representa la pantalla
	int xPantalla = marco->GetX() -
		g->VisibleClipBounds.Width / 2;

	x = xPantalla;

	// Validacion
	if (marco->GetX() < g->VisibleClipBounds.Width / 2)
		x = 0;
	else if (wfondo - marco->GetX() < g->VisibleClipBounds.Width / 2)
		x = wfondo - g->VisibleClipBounds.Width;

	int yPantalla = marco->GetY() -
		g->VisibleClipBounds.Height / 2;

	y = yPantalla;
	// Validacion
	if (marco->GetY() < g->VisibleClipBounds.Height / 2)
		y = 0;
	else if (hfondo - marco->GetY() < g->VisibleClipBounds.Height / 2)
		y = hfondo - g->VisibleClipBounds.Height;

	// Dibujo el Fondo
	gFondo->DrawImage(bmp, 0, 0,
		wfondo, hfondo);

	// Dibujo el Personaje
	marco->dibujar(gFondo, bmpM);

	//dibujar dialog box 
	//porque dibuja el dialog siempre??
	marco->dibujarDialogo(gFondo, bmpD,dialogo,x,y,wfondo,hfondo);

	// Rectangulos de Origen y Destino
	Rectangle rOrigen(0, 0,
		g->VisibleClipBounds.Width,
		g->VisibleClipBounds.Height);
	Rectangle rDestino(x, y,
		g->VisibleClipBounds.Width,
		g->VisibleClipBounds.Height);

	// Dibujando la Pantalla
	g->DrawImage(bmFondo, rOrigen, rDestino,
		GraphicsUnit::Pixel);



}
void CControlador::QuietoMarco(Keys key)
{
	marco->quieto(key);
}
void CControlador::dibujarDialogo(Graphics^ g, Bitmap^bmpD,Label^dialogo, int x, int y, int wpantalla, int hpantalla)
{
	marco->dibujarDialogo(g, bmpD,dialogo,x,y,wpantalla,hpantalla);
	
}
void CControlador::marcoHablar(Keys key,Label^dialogo)
{
	marco->hablar(key ,dialogo);
}