#pragma once
#include "PrismaRectangular.h"

class Bonus :public PrismaRectangular {
	bool tipo;//Tipo false: Vida, tipo true: escudo
public:
	~Bonus();
	Bonus(Vector3D a,Vector3D b,bool tip);
	void dibuja();
	bool destruye(float z);
	friend class Interaccion;
};