#include "ListaObstaculos.h"



ListaObstaculos::ListaObstaculos():numero(0)
{
	for (int i = 0; i < MAX; i++)//Se inicializan los punteros
		lista[i] = NULL;
}


ListaObstaculos::~ListaObstaculos()
{
}

bool ListaObstaculos::agregar(PrismaRectangular *o)//Metodo para agregar un obstaculo si no se ha llegado al maximo
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

void ListaObstaculos::añadirObstaculo(float coordz,float mult) {//Se añaden obstaculos en funcion de la velocidad del ojo y de la z
	static float frecuencia = 30;//frecuencia de llamada de la funcion-> 1 vez cuando pasan 30*25ms
	frecuencia-=1;
	if (frecuencia < 0) {//Cuando pasa el tiempo requerido se crea un obstaculo
		PrismaRectangular *aux = new PrismaRectangular(Vector3D(-4, 0, coordz-240), Vector3D(4, 2, coordz - 241));
		agregar(aux);
		int num = ETSIDI::lanzaDado(5);//El tiempo que tardará en crearse el siguiente obstaculo tendra varios posibles valores
		frecuencia = (num+3)*60/mult;  //La finalidad de esto es que la separacion entre obstaculos no sea siempre la misma
	}
	
}

void ListaObstaculos::destructorObstaculos(float coordz) {//destruccion de obstaculos cuando se ponen por detras del ojo
	for (int i = 0; i <numero; i++) {
		if (coordz < lista[i]->getP1().z) {
			delete lista[i];
			numero--;
			for (int j = i; j < numero; j++)
				lista[j] = lista[j + 1];
		}
	}
}
void ListaObstaculos::destructorObstaculos() {
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}