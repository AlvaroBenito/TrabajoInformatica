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
	void cogerMonedas(Personaje personaje);

	void generadorMonedas(float coordz);
	void descructorMonedas(float coordz);
	void añadirMoneda(float coordz,float mult);
	void eliminar(int index);

private:
	Moneda * lista[MAX_MONEDAS];
	int    numero;
	bool agr;//True->se pueden agregar monedas, False-> No se pueden agregar monedas
};
