#pragma once
#include "PrismaRectangular.h"

class Bonus :public PrismaRectangular {
	bool tipo;//Tipo false: Vida, tipo true: escudo
public:
	Bonus(Vector3D a,Vector3D b,bool tip);
	void dibuja();
	friend class Interaccion;
};