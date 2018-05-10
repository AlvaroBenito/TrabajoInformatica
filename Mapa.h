#pragma once
#include "PrismaRectangular.h"
//Clase para dibujar el mapa, que tendrá suelo, paredes externas, e incluso podriamos meter los obstaculos aqui en vez de en la clase Elemento
class Mapa {
	PrismaRectangular lateralDer;
	PrismaRectangular lateralIzq;
	PrismaRectangular suelo;
public:
	void dibuja();
};