#pragma once
#include "Bonus.h"
#define MAX_BONUS 30
class ListaBonus {
	Bonus * lista[MAX_BONUS];
	int numero;
	friend class Interaccion;
public:
	ListaBonus();
	//~ListaBonus();
	bool agregar(Bonus *e);
	void dibuja();
	void añadirBonus(float coordz, float mult);
	void destructorBonus(float coordz);
	void destructorBonus();
	void eliminar(int index);
	friend class Interaccion;

};