#pragma once
#include "Vector3D.h"

class Plataforma
{
public:
	Plataforma();
	virtual ~Plataforma();
	/*void dibuja();
	void setColor(int r, int v, int a);
	void setPos(float x1, float y1, float x2, float y2);
	float distancia(Vector3D punto, Vector3D *direccion);
	*/
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	Vector3D limite1;
	Vector3D limite2;
	
};

