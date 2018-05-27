#pragma once
#include "Color.h"
#include "Vector3D.h"
//La finalidad de esta clase es poder hacer los muros laterales como si fueran prismas rectangulares en vez de simples planos
class PrismaRectangular {
	Vector3D p1;
	Vector3D p2;
	Color RGB;
	friend class Interaccion;
	static int tipoMaterial;
public:
	PrismaRectangular(Vector3D coor1, Vector3D coor2);
	PrismaRectangular();
	void dibuja();
	void dibuja2(Vector3D a, Vector3D b);
	Vector3D getP1();
	Vector3D getP2();
	void setP1_P2(Vector3D a, Vector3D b);
	static void setMaterial(int t);
	static int getMaterial();
};
