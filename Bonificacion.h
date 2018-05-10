#pragma once
#include "Bonus.h"
class Bonificacion :public Bonus {
	float radio;//Ya veremos que forma le damos
	bool tipo;//Luego podemos de hecho hacer herencia para programar los tipos de bonificacion
public:
	Bonificacion();
	virtual ~Bonificacion();
	

};