#include "ListaTrampas.h"



ListaTrampas::ListaTrampas()
{
}


ListaTrampas::~ListaTrampas()
{
}


bool ListaTrampas::agregar(Trampa *trampa)
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

void ListaTrampas::generadorTrampas(float coordz) {
	
	for (float i = coordz - 50; i > coordz - 80; i = i - 5) {
		Trampa* aux = new Trampa(ETSIDI::lanzaDado(4) - 2, i);
		agregar(aux);
	}
}

void ListaTrampas::descructorTrampas(float coorz) {

	for (int i = 0; i <numero; i++) {
		if (coorz < lista[i]->getLim1().z) {
			delete lista[i];
			numero--;
			for (int j = i; j < numero; j++)
				lista[j] = lista[j + 1];
		}
	}
}