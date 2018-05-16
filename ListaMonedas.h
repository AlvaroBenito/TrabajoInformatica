#pragma once
#include "Moneda.h"
#include "Personaje.h"
#define MAX_MONEDAS 100

class ListaMonedas
{
public:
	ListaMonedas();
	~ListaMonedas();
	bool agregar(Moneda *e);
	void dibuja();
	void rotar();
	void rebote(Personaje personaje);

private:
	Moneda * lista[MAX_MONEDAS];
	int    numero;
};
