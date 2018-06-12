#pragma once
#include "Trampa.h"
#include "Personaje.h"

#define MAX_TRAMPAS 30

class ListaTrampas
{
public:
	ListaTrampas();
	~ListaTrampas();
	bool agregar(Plano *trampa);//Agrega una trampa al vector
	void dibuja();
	void destructorTrampas(float coordz);//Destruye las trampas que se quedan por detras del ojo
	void añadirTrampa(float coordz, float mult);//Se añaden trampas en funcion del eje z y de la velocidad del ojo
	void destructorTrampas();//Eliminar todas las trampas
	friend class Interaccion;
private:
	Plano * lista[MAX_TRAMPAS];//Vector de trampas y suelosmalos utilizando polimorfismo
	int    numero;
	bool agr;//True->se pueden agregar trampas, False-> No se pueden agregar trampas
};