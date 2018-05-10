#pragma once
#include "Elemento.h"
class Personaje :public Elemento {
	int vidas;
	bool escudo;
	int contMonedas;
public:
	Personaje();
	virtual ~Personaje();
	void Dibuja();
	int getVidas();
};