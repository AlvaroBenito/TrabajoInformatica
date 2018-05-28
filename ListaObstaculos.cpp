#include "ListaObstaculos.h"



ListaObstaculos::ListaObstaculos()
{
}


ListaObstaculos::~ListaObstaculos()
{
}

bool ListaObstaculos::agregar(Obstaculo *e)
{
	if (numero<MAX)
		lista[numero++] = e;
	else
		return    false;
	return    true;
}

void ListaObstaculos::dibuja()
{
	for (int i = 0; i<numero; i++)
		lista[i]->dibuja();
}

void ListaObstaculos::generadorObstaculos(float coordz) {

	if (ETSIDI::lanzaDado(3) - 1) {
		for (int i = -60; i > -200; i -= 120) {
			Obstaculo * aux = new Obstaculo(coordz + i);
			agregar(aux);
		}
	}
	else {
		Obstaculo * aux = new Obstaculo(coordz - 140);
		agregar(aux);
	}
}

void ListaObstaculos::destructorObstaculos(float coordz) {
	for (int i = 0; i <numero; i++) {
		if (coordz < lista[i]->getP1().z) {
			delete lista[i];
			numero--;
			for (int j = i; j < numero; j++)
				lista[j] = lista[j + 1];
		}
	}
}