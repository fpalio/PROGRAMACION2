#include "stdafx.h"
#include "Marco.h"


CMarco::CMarco(int x, int y, int w, int h, int dx, int dy)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->dx = dx;
	this->dy = dy;
	estado = ARRIBA;
	frame = 0;
	dialogoV = false;
	


}


CMarco::~CMarco()
{
}
void CMarco::dibujar(Graphics^ g, Bitmap^ bmp)
{
	int wOrigen = bmp->Size.Width / 3;
	int hOrigen = bmp->Size.Height / 4;
	int xOrigen = frame* wOrigen;       
	int yOrigen = estado * hOrigen;

	Rectangle rOrigen = Rectangle(xOrigen, yOrigen, wOrigen, hOrigen);
	Rectangle rDestino = Rectangle(x, y, h, w);
	g->DrawImage(bmp, rDestino, rOrigen, GraphicsUnit::Pixel);
}
void CMarco::mover(int limX, int limY, Keys key)
{
	switch (key)
	{
	case Keys::Up:
		if (estado != ESTADO::ARRIBA)
		{
			estado = ESTADO::ARRIBA;
			frame = 0;
		}
		else
		{
			frame++;
			if (frame >= 3)
			frame = 0;
		}
		if (y - dy > 0)
			y = y - dy;
		break;
	case Keys::Down:
		if (estado != ESTADO::ABAJO)
		{
			estado = ESTADO::ABAJO;
			frame = 0;
		}
		else
		{
			frame++;
			if (frame >= 3)
				frame = 0;
		}
		if (y + dy + h < limY)
			y = y + dy;
		break;
	case Keys::Right:
		if (estado != ESTADO::DERECHA)
		{
			estado = ESTADO::DERECHA;
			frame = 0;
		}
		else
		{
			frame++;
			if (frame >= 3)
				frame = 0;
		}
		if (x + dx + w < limX)
			x = x + dx;
		break;
	case Keys::Left:
		if (estado != ESTADO::IZQUIERDA)
		{
			estado = ESTADO::IZQUIERDA;
			frame = 0;
		}
		else
		{
			frame++;
			if (frame >= 3)
				frame = 0;
		}
		if (x - dx > 0)
			x = x - dx;
		break;

	}

}
int CMarco::GetX()
{
	return x;
}
int CMarco::GetY()
{
	return y;
}
int CMarco::GetH()
{
	return h;
}
int CMarco::GetW()
{
	return w;
}
void CMarco::quieto(Keys key)
{
	switch(key)
	{
	case Keys::Up:
	case Keys::Down:
	case Keys::Right:
	case Keys::Left:
		frame = 0;
		break;
	}
	
}
void CMarco::dibujarDialogo(Graphics^ g, Bitmap^bmpD, int xpantalla, int ypantalla, int wpantalla, int hpantalla)
{
	int hDialogo = hpantalla/4;
	int wDialogo =wpantalla/2 + 200 ;
	int wOrigen = g->VisibleClipBounds.Width;
	int hOrigen = g->VisibleClipBounds.Height/2;

	Rectangle rOrigen = Rectangle(0, 0, wOrigen, hOrigen);
	Rectangle dOrigen = Rectangle(xpantalla+10, ypantalla+220 ,
		wDialogo, hDialogo);
	if (dialogoV==true)
	g->DrawImage(bmpD, dOrigen, rOrigen, GraphicsUnit::Pixel);
	

}
void CMarco::hablar(Keys key)
{
	if (key == Keys::Space)
		dialogoV = !dialogoV;
}