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

public:
	Plano();
	Plano(Vector3D coor1, Vector3D coor2);
	virtual void dibuja();
	void setMaterial(int t);
	Vector3D getLim1() { return limite1; }
};

