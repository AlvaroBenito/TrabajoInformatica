#pragma once
#include "Trampa.h"
#include "Personaje.h"

#define MAX_TRAMPAS 30

class ListaTrampas
{
public:
	ListaTrampas();
	~ListaTrampas();
	bool agregar(Plano *trampa);
	void dibuja();
	void destructorTrampas(float coordz);
	void aņadirTrampa(float coordz, float mult);
	void destructorTrampas();
	friend class Interaccion;
private:
	Plano * lista[MAX_TRAMPAS];
	int    numero;
	bool agr;//True->se pueden agregar trampas, False-> No se pueden agregar trampas
};