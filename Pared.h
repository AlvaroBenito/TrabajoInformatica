
#pragma once


#include "Vector2D.h"


class Pared  
{
	friend class Interaccion;
public:
	Pared();
	virtual ~Pared();
	void dibuja();
	void setColor(int r, int v, int a);
	void setPos(float x1, float y1, float x2, float y2);
	float distancia(Vector2D punto, Vector2D *direccion);
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	Vector2D limite1;
	Vector2D limite2;
	
};
