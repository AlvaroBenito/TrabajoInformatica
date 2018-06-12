#pragma once
#include "Moneda.h"
#include "Personaje.h"


#define MAX_MONEDAS 28

class ListaMonedas
{
public:
	ListaMonedas();
	~ListaMonedas();
	bool agregar(Moneda *e);//funcion para agregar moneda
	void dibuja();
	void rotar();
	void cogerMonedas(Personaje personaje);//Funcion para coger las monedas(No incluida en interaccion)
	void destructorMonedas(float coordz);//Destruccion de las monedas
	void añadirMoneda(float coordz,float mult);//Creacion de monedas en funcion de la frecuencia
	void eliminar(int index);//Eliminar una moneda 
	void destructorMonedas();//Eliminar todas las monedas
	friend class Interaccion;
private:
	Moneda * lista[MAX_MONEDAS];
	int    numero;
	bool agr;//True->se pueden agregar monedas, False-> No se pueden agregar monedas
};
