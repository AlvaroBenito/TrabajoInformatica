#pragma once
#include "Vector3D.h"
#include "PrismaRectangular.h"
#include "Vector3D.h"
class Portal {
	float radio_int;
	float radio_ext;
public:
	unsigned char rojo;
	unsigned char azul;
	float z;
	Portal();
	~Portal();
	void dibuja();
};