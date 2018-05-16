#pragma once
#define MAX_ESFERAS 100 
#include "Esfera.h"
#include "Interaccion.h"


class ListaEsferas
{
public:
	ListaEsferas();
	~ListaEsferas();
	bool agregar(Esfera *e);
	void dibuja();
	void mueve(float t);
	void rebote(Caja caja);
	void rebote(Pared p);
	void rebote();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Esfera *e);
	Esfera * colision(Esfera &e);
	

private:
	Esfera * lista[MAX_ESFERAS];
	int    numero;
};

