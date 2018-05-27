#pragma once
#include "Personaje.h"
#include "Mapa.h"
#include "Moneda.h"
class Interaccion {
public:
	static bool reboteSuelo(PrismaRectangular suelo, Personaje &p);
	static bool mueveCentro(PrismaRectangular suelo, Personaje &p);
	static bool choqueParedes(PrismaRectangular paredDer,PrismaRectangular paredIzq, Personaje &p);
	static bool cogerMoneda(Moneda mon, Personaje &p);
};