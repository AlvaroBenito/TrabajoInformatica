#pragma once
#include "Elemento.h"
#define RADIO_MONEDA_OUT 0.2f
#define RADIO_MONEDA_IN 0.05f
class Moneda :public Elemento {
	
	//static int monedasRecogidas;
	float anguloRotacion;

public:

	Moneda();
	Moneda(float posx, float posy, float posz, float vel=0);
	void setPos(Vector3D pos);
	void dibuja();
	void rotar(float t=5);
	
	//void sumaMoneda();//funcion para que cuando se coja la moneda, se sume 1 a la cuenta de Personaje
	//Esto se hace con un atributo static en la clase

};

//int Moneda::monedasRecogidas = 0;
