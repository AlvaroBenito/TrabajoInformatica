#include "ListaObstaculos.h"



ListaObstaculos::ListaObstaculos():numero(0)
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

void ListaObstaculos::añadirObstaculo(float coordz,float mult) {
	static float frecuencia = 30;
	frecuencia-=1;
	if (frecuencia < 0) {
		Obstaculo *aux = new Obstaculo(coordz - 240);
		agregar(aux);
		int num = ETSIDI::lanzaDado(5);
		frecuencia = (num+3)*60/mult;
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