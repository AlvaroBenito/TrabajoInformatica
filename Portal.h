#pragma once
#include "Vector3D.h"
#include "PrismaRectangular.h"
#include "Vector3D.h"
class Portal {
	float radio_int;
	float radio_ext;
	float z;
public:
	Portal();
	~Portal();
	void dibuja();
	float getZ();
	void setZ(float zi);
};