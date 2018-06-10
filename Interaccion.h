#pragma once
#include "Personaje.h"
#include "Mapa.h"
#include "Moneda.h"
#include "ListaObstaculos.h"
#include "ListaTrampas.h"
#include "Bonus.h"
#include "ListaBonus.h"
#include "ListaMonedas.h"
class Interaccion {
public:
	static bool reboteSuelo(PrismaRectangular suelo, Personaje &p);
	static bool mueveCentro(PrismaRectangular suelo, Personaje &p);
	static bool choqueParedes(PrismaRectangular paredDer,PrismaRectangular paredIzq, Personaje &p);
	static bool cogerMoneda(Moneda mon, Personaje &p);
	static bool reboteObstaculo(PrismaRectangular *obstaculo, Personaje &p);
	static bool reboteObstaculo(ListaObstaculos obstaculo, Personaje &p);
	static bool condicionDibujo(Plano *p, PrismaRectangular *o);
	static bool condicionDibujo(ListaTrampas &t, ListaObstaculos o);
	static bool colisionTrampas(Plano *plano, Personaje &p);
	static bool colisionTrampas(ListaTrampas t, Personaje &p);
	static bool cogeBonus(Bonus *bon, Personaje &p);
	static bool redibujaMon(Moneda *mon, PrismaRectangular *o);
	static bool redibujaMon(ListaMonedas mon, ListaObstaculos obs);
};