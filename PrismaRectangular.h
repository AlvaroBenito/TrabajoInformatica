#pragma once
#include "Vector3D.h"
//La finalidad de esta clase es poder hacer los muros laterales como si fueran prismas rectangulares en vez de simples planos
class PrismaRectangular {
protected:
	Vector3D p1;
	Vector3D p2;
	static int tipoMaterial;
	bool impacto;//Variable que usan las clases hijas de "Plano" para que solo se aplique una colision con el personaje en vez de varias
public:
	PrismaRectangular(Vector3D coor1, Vector3D coor2);
	PrismaRectangular();
	void dibuja();
	static void dibuja2(Vector3D a, Vector3D b);
	Vector3D getP1();
	Vector3D getP2();
	static void setMaterial(int t);
	static int getMaterial();
	friend class Interaccion;
};
inline void PrismaRectangular::setMaterial(int t) {
	tipoMaterial = t;
}
inline int PrismaRectangular::getMaterial() {
	return tipoMaterial;
}
inline Vector3D PrismaRectangular::getP1() {
	return p1;
}
inline Vector3D PrismaRectangular::getP2() {
	return p2;
}
