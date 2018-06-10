#pragma once
#include "ETSIDI.h"
#include "PrismaRectangular.h"
#define MAX 15


class ListaObstaculos{
	PrismaRectangular * lista[MAX];
	int numero;
	friend class Interaccion;
public:
	ListaObstaculos();
	~ListaObstaculos();
	bool agregar(PrismaRectangular *e);
	void dibuja();
	void añadirObstaculo(float coordz,float mult);
	void destructorObstaculos(float coordz);
	void destructorObstaculos();
	void eliminar(int index);
};

