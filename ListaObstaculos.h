#pragma once
#include "obstaculo.h"
#include "ETSIDI.h"
#define MAX 15


class ListaObstaculos{
	Obstaculo * lista[MAX];
	int numero;
	friend class Interaccion;
public:
	ListaObstaculos();
	~ListaObstaculos();
	bool agregar(Obstaculo *e);
	void dibuja();
	void añadirObstaculo(float coordz,float mult);
	void destructorObstaculos(float coordz);
	
};

