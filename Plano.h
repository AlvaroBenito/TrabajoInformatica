#pragma once
#include "Vector3D.h"

class Plano {

	Vector3D limite1;
	Vector3D limite2;
	int tipoMaterial;

public:

	//static int material;
	Plano();
	Plano(Vector3D coor1, Vector3D coor2);
	void dibuja();
	void setMaterial(int t);
};

