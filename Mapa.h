#pragma once
#include "PrismaRectangular.h"
#include "Plataforma.h"
//Clase para dibujar el mapa, que tendr� suelo, paredes externas, e incluso podriamos meter los obstaculos aqui en vez de en la clase Elemento
class Mapa {
	Plataforma camino;
public:
	Mapa();
	void dibuja();
};
