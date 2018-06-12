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
	bool agregar(PrismaRectangular *e);//Metodo para agregar un obstaculo
	void dibuja();
	void a�adirObstaculo(float coordz,float mult);//Metodo para a�adir un obstaculo en una coordenada z especifica
	void destructorObstaculos(float coordz);//Metodo para destruir obstaculos en funcion de su coordenada z
	void destructorObstaculos();//Eliminar todos los obstaculos
};

