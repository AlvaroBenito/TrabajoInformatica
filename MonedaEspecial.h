#pragma once
#include "Moneda.h"

class MonedaEspecial :public Moneda {
public:
	MonedaEspecial(float posx, float posy, float posz, float vel = 0);
	void dibuja();
};