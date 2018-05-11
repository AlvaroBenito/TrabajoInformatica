#pragma once
#include "Elemento.h"
class Personaje :public Elemento {
	int vidas;
	bool escudo;
	int contMonedas;
public:
	void Dibuja();
	int getVidas();
};