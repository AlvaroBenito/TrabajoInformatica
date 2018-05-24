#pragma once
#include "Moneda.h"
#include "Personaje.h"


#define MAX_MONEDAS 60

class ListaMonedas
{
public:
	ListaMonedas();
	~ListaMonedas();
	bool agregar(Moneda *e);
	void dibuja();
	void rotar();
	void rebote(Personaje personaje);

	void generadorMonedas();
	void descructorMonedas(float coordz);

private:
	Moneda * lista[MAX_MONEDAS];
	int    numero;
};
