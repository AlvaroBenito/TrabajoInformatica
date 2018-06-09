#pragma once
#include "Vector3D.h"
#include "Elemento.h"
#include "PrismaRectangular.h"


class Obstaculo : public Elemento, public PrismaRectangular{
public:
	Obstaculo();
	Obstaculo(float coordz);
	~Obstaculo();
	//void dibuja();
	friend class Interaccion;
};

