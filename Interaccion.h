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
	static bool reboteSuelo(PrismaRectangular suelo, Personaje &p);//Interaccion del personaje para que se detenga cuando toca el suelo
	static bool mueveCentro(PrismaRectangular suelo, Personaje &p);//Interaccion del personaje para que funcionen los tres carriles
	static bool choqueParedes(PrismaRectangular paredDer,PrismaRectangular paredIzq, Personaje &p);//Metodo para no salirse de la plataforma
	static bool cogerMoneda(Moneda mon, Personaje &p);//Metodo para coger una moneda
	static bool reboteObstaculo(PrismaRectangular *obstaculo, Personaje &p);//Impacto con un obstaculo
	static bool reboteObstaculo(ListaObstaculos obstaculo, Personaje &p);//Impacto con todos los obstaculos
	static bool condicionDibujo(Plano *p, PrismaRectangular *o);//Condicion para no dibujar trampas y obstaculos en el mismo sitio
	static bool condicionDibujo(ListaTrampas &t, ListaObstaculos o);//Comprobacion del metodo anterior con todas las trampas y obstaculos
	static bool colisionTrampas(Plano *plano, Personaje &p);//Colision con una trampa
	static bool colisionTrampas(ListaTrampas t, Personaje &p);//Colision con todas las trampas
	static bool cogeBonus(Bonus *bon, Personaje &p);//Funcion para coger el bonus
	static bool redibujaMon(Moneda *mon, PrismaRectangular *o);//Funcion para dibujar correctamente las monedas respecto a los obstaculos
	static bool redibujaMon(ListaMonedas mon, ListaObstaculos obs);
};