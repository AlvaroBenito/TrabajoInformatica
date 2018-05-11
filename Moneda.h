#pragma once
#include "Elemento.h"
class Moneda :public Elemento {
	float radio;

	//static int monedasRecogidas;

public:
	Moneda();
	virtual ~Moneda();
	void dibuja();
	//void sumaMoneda();//funcion para que cuando se coja la moneda, se sume 1 a la cuenta de Personaje
	//Esto se hace con un atributo static en la clase

};

//int Moneda::monedasRecogidas = 0;
