#pragma once
#include "Trampa.h"
#include "Personaje.h"

#define MAX_TRAMPAS 50

class ListaTrampas
{
public:
	ListaTrampas();
	~ListaTrampas();
	bool agregar(Plano *trampa);
	void dibuja();
	void descructorTrampas(float coordz);
	void añadirTrampa(float coordz, float mult);
	void eliminar(int index);
	friend class Interaccion;
private:
	Plano * lista[MAX_TRAMPAS];
	int    numero;
	bool agr;//True->se pueden agregar trampas, False-> No se pueden agregar trampas
};



