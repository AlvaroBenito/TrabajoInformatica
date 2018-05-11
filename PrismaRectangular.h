#pragma once
#include "Color.h"
#include "Vector3D.h"
//La finalidad de esta clase es poder hacer los muros laterales como si fueran prismas rectangulares en vez de simples planos
class PrismaRectangular {
	Vector3D p1;
	Vector3D p2;
	Color RGB;
public:
	PrismaRectangular(Vector3D coor1, Vector3D coor2);
	void dibuja();
};