#pragma once
#include "Trampa.h"
#include "Personaje.h"

#define MAX_TRAMPAS 5

class ListaTrampas
{
public:
	ListaTrampas();
	~ListaTrampas();
	bool agregar(Trampa *trampa);
	void dibuja();
	void generadorTrampas(float coordz);
	void descructorTrampas(float coordz);
	void añadirTrampa(float coordz, float mult);
	void eliminar(int index);

private:
	Trampa * lista[MAX_TRAMPAS];
	int    numero;
	bool agr;//True->se pueden agregar trampas, False-> No se pueden agregar trampas
};



