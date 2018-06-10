#pragma once
#include "Vector3D.h"

class Elemento {
protected:
	Vector3D posicion;
	Vector3D velocidad;
	float aceleracionY;
public:
	Elemento();
	void mueve(float vel);
	void setPosZ(float z);
	Vector3D getPos();
};