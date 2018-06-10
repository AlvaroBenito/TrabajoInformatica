#include "ListaTrampas.h"
#include "SueloMalo.h"
ListaTrampas::ListaTrampas():numero(0)
{
	for (int i = 0; i < MAX_TRAMPAS; i++) {
		lista[i] = NULL;
	}
}


ListaTrampas::~ListaTrampas()
{
}


bool ListaTrampas::agregar(Plano *trampa)
{
	if (numero<MAX_TRAMPAS)
		lista[numero++] = trampa;
	else
		return    false;
	return    true;
}

void ListaTrampas::dibuja()
{
	for (int i = 0; i<numero; i++)
		lista[i]->dibuja();
}

void ListaTrampas::añadirTrampa(float coordz,float mult) {
	static float frecuencia = 250;
	int num = ETSIDI::lanzaDado(6);
	if (num < 3) {
		if (agr) {
			agregar(new SueloMalo(ETSIDI::lanzaDado(4)-2, coordz - 100));
			//agregar(new SueloMalo(0, coordz - 100));
			//agregar(new SueloMalo(1, coordz - 100));
			agr = false;
		}
	}
	else {
		if (agr) {
			for (int i = 0; i < 3; i++) {
				int pos1 = ETSIDI::lanzaDado(4) - 2;
				int pos2 = ETSIDI::lanzaDado(4) - 2;
				while (pos2 == pos1) {
					pos2 = ETSIDI::lanzaDado(4) - 2;
				}
				agregar(new Trampa((float)pos1, coordz - 240 - 10 * i));
				agregar(new Trampa((float)pos2, coordz - 240 - 10 * i));

			}
			agr = false;
		}
	}
	frecuencia -= 1;
	if (frecuencia < 0) {//Frecuencia de creacion de monedas dentro de un grupo de monedas
		frecuencia = 250 / mult;//Mult para que dependa de la velocidad del ojo
		agr = true;//Cuando pasa el tiempo necesario, se permite crear una moneda
	}
}

void ListaTrampas::destructorTrampas(float coorz) {

	for (int i = 0; i <numero; i++) {
		if (coorz < lista[i]->getLim1().z) {
			delete lista[i];
			numero--;
			for (int j = i; j < numero; j++)
				lista[j] = lista[j + 1];
		}
	}
}
void ListaTrampas::destructorTrampas() {
	for (int i = 0; i < numero; i++) {
		delete lista[i];
		lista[i] = NULL;
	}

	numero = 0;
}