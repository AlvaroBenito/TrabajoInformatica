#pragma once
#include "PrismaRectangular.h"
#include "Plataforma.h"
#include "Portal.h"
//Clase para dibujar el mapa, que tendrá suelo, paredes externas, e incluso podriamos meter los obstaculos aqui en vez de en la clase Elemento
class Mapa {
	Plataforma *camino;
	bool inicializa;
	int n;
public:
	Mapa();
	void dibuja();
	void cambia(float mult);
	Plataforma getSuelo(int i);
};

