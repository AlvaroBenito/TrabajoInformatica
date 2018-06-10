#include <stdlib.h>
#include "ListaMonedas.h"
#include <cstdlib>
#include "ETSIDI.h"
#include "Interaccion.h"
#include "MonedaEspecial.h"
ListaMonedas::ListaMonedas():numero(0)
{
	for (int i = 0; i < MAX_MONEDAS; i++)
		lista[i] = NULL;
}

ListaMonedas::~ListaMonedas()
{
}

bool ListaMonedas::agregar(Moneda *moneda)
{
	if (numero<MAX_MONEDAS)
		lista[numero++] = moneda;
	else
		return    false;
	return    true;
}

void ListaMonedas::dibuja()
{
	for (int i = 0; i<numero; i++)
		lista[i]->dibuja();
}
void ListaMonedas::rotar()
{
	Moneda::sumaAnguloRot(5.0f);
}
void ListaMonedas::cogerMonedas(Personaje p) {
	bool aux = false;
	for (int i = 0; i < numero; i++) {
		aux=Interaccion::cogerMoneda(*lista[i], p);
		if (aux) {
			eliminar(i);
		}
		
	}
}
void ListaMonedas::generadorMonedas(float coordz){
	float pos = (float)ETSIDI::lanzaDado(4) - 2;//como la distancia entre cada carril es 1, se aprovecha para obtener facilmente uno de los numeros: -1,0,1 de los tres carriles
		for (float i = coordz-50; i > coordz - 85; i = i - 5) {
			Moneda* aux = new Moneda(pos, 0.96f, i);
			agregar(aux);
		}
}

void ListaMonedas::descructorMonedas(float coorz) {

	for (int i = 0; i <numero; i++) {
		if (coorz < lista[i]->getPos().z) {
			delete lista[i];
			numero--;
			for (int j = i; j < numero; j++)
				lista[j] = lista[j + 1];
		}
	}
}
void ListaMonedas::añadirMoneda(float coorz,float mult) {
	static int grupo = 7;
	static float pos = (float)ETSIDI::lanzaDado(4) - 2;
	static float cuentaMon = 50;
	if (agr) {
		bool monedaEsp = false;
		int num = ETSIDI::lanzaDado(8);
		if (num == 1) monedaEsp = true;
		if (monedaEsp) {
			Moneda *aux1 = new MonedaEspecial(pos, 0.96f, coorz - 120);
			agregar(aux1);
		}
		else {
			Moneda *aux2 = new Moneda(pos, 0.96f, coorz - 120);
			agregar(aux2);
		}
		agr = false;//Despues de crear una moneda, se espera para poder crear la siguiente
		grupo--;
	}
	if (grupo == 0) {
		pos = (float)ETSIDI::lanzaDado(4) - 2;
		grupo = 7;
		agr = false;
		cuentaMon = 150.0f/mult;//Tiempo desde que muere un grupo de monedas hasta que aparece otro
	}
	cuentaMon--;
	if (cuentaMon < 0 && grupo != 0) {//Frecuencia de creacion de monedas dentro de un grupo de monedas
		cuentaMon = 12.0f/mult;//Mult para que dependa de la velocidad del ojo
		agr = true;//Cuando pasa el tiempo necesario, se permite crear una moneda
	}
}
void ListaMonedas::eliminar(int index) {
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
