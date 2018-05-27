#pragma once
#include "Elemento.h"
class Personaje :public Elemento {
	int vidas;
	bool escudo;
	static int contMonedas;
	friend class Interaccion;
	float aceleracionY;
	bool centro;//variable para saber si el personaje esta en el carril central
	bool salto;//Variable para comprobar si puede o no saltar
public:
	Personaje();
	void dibuja();
	void gira(bool der);
	int getVidas();
	int getContMonedas();
	void sumaMoneda();
	void salta();
};