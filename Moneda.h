#pragma once
#include "Bonus.h"
class Moneda :public Bonus {
	float radio_int;//la podemos hacer a modo toroide o en plan con los bordes mas gruesos que el interior
	float radio_ext;
public:
	Moneda();
	virtual ~Moneda();
	void sumaMoneda();//funcion para que cuando se coja la moneda, se sume 1 a la cuenta de Personaje

};