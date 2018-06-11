#pragma once
#include "Vector3D.h"
#include <stdlib.h>
#include "glut.h"
#include "ETSIDI.h"

class Plano {

protected:
	Vector3D limite1;
	Vector3D limite2;
	int tipoMaterial;
	bool impacto; //Variable que usan las clases hijas de "Plano" para que solo se aplique una colision con el personaje en vez de varias
public:
	Plano();
	Plano(Vector3D coor1, Vector3D coor2);
	virtual void dibuja();
	void setMaterial(int t);
	Vector3D getLim1();
	friend class Interaccion;
};
inline void Plano::setMaterial(int t) {
	tipoMaterial = t;
}
inline Vector3D Plano::getLim1() {
	return limite1;
}
