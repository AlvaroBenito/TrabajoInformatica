#pragma once
#include "Elemento.h"
class Personaje :public Elemento {
	int vidas;
	bool escudo;
	int contMonedas;
	friend class Interaccion;
public:
	Personaje();
	void dibuja();
	int getVidas();
};