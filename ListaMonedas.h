#pragma once
#include "Moneda.h"
#include "Personaje.h"


#define MAX_MONEDAS 28

class ListaMonedas
{
public:
	ListaMonedas();
	~ListaMonedas();
	bool agregar(Moneda *e);
	void dibuja();
	void rotar();
	void rebote(Personaje personaje);

	void generadorMonedas(float coordz);
	void descructorMonedas(float coordz);
	void a�adirMoneda(float coordz);

private:
	Moneda * lista[MAX_MONEDAS];
	int    numero;
	bool agr;
};
