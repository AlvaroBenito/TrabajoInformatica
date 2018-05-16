#pragma once


#include "Vector2D.h"


class Esfera  
{
	friend class Interaccion;
public:
	Esfera();
	virtual ~Esfera();
	
	void mueve(float t);
	void dibuja();

	void setColor(int r, int v, int a);
	void setRadio(float r);
	void setPos(float ix,float iy);
	void setVel(float vx, float vy);
	Esfera(float rad, float x = 0.0f, float y = 0.0f, float vx = 0.0f, float vy = 0.0f);

private:
	
	float radio;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
};


