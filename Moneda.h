#pragma once
#include "Elemento.h"
#define RADIO_MONEDA_OUT 0.2f
#define RADIO_MONEDA_IN 0.05f
class Moneda :public Elemento {
public:
	static float anguloRotacion;

public:

	Moneda();
	Moneda(float posx, float posy, float posz, float vel = 0);
	void setPos(Vector3D pos);
	void dibuja();
};


