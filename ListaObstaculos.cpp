#include "ListaObstaculos.h"



ListaObstaculos::ListaObstaculos():numero(0)
{
	for (int i = 0; i < MAX; i++)
		lista[i] = NULL;
}


ListaObstaculos::~ListaObstaculos()
{
}

bool ListaObstaculos::agregar(PrismaRectangular *o)
{
	if (numero<MAX)
		lista[numero++] = o;
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
		PrismaRectangular *aux = new PrismaRectangular(Vector3D(-4, 0, coordz-240), Vector3D(4, 2, coordz - 241));
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