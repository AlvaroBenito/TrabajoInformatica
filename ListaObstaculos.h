#pragma once
#include "obstaculo.h"
#include "ETSIDI.h"
#define MAX 2


class ListaObstaculos{
	Obstaculo * lista[MAX];
	int numero;
	friend class Interaccion;
public:
	ListaObstaculos();
	~ListaObstaculos();
	bool agregar(Obstaculo *e);
	void dibuja();
	void generadorObstaculos(float coordz);
	void destructorObstaculos(float coordz);
	
};

