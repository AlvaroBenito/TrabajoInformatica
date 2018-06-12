#include "ListaTrampas.h"
#include "SueloMalo.h"
ListaTrampas::ListaTrampas():numero(0)
{
	for (int i = 0; i < MAX_TRAMPAS; i++) {//Se inicializan los punteros a NULL
		lista[i] = NULL;
	}
}


ListaTrampas::~ListaTrampas()
{
}


bool ListaTrampas::agregar(Plano *trampa)//Se agregan trampas sin superar el máximo
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
	int num = ETSIDI::lanzaDado(6);//Numero para determinar si se crea suelo malo o trampa
	if (num < 3) {
		if (agr) {//Solo se agregan objetos si la variable agr lo permite
			agregar(new SueloMalo(ETSIDI::lanzaDado(4)-2, coordz - 100));//La posicion en el eje x es uno de los carriles de forma aleatoria
			agr = false;//tras agregar suelomalo, no se permite volver a agregar una trampa
		}
	}
	else {
		if (agr) {
			for (int i = 0; i < 4; i++) {//Bucle para crear varias parejas de trampas
				int pos1 = ETSIDI::lanzaDado(4) - 2;//Se desean crear dos trampas, cada una en un carril distinto pero en la misma z
				int pos2 = ETSIDI::lanzaDado(4) - 2;
				while (pos2 == pos1) {//Bucle para asegurar que las trampas no se dibujan en el mismo carril
					pos2 = ETSIDI::lanzaDado(4) - 2;
				}
				agregar(new Trampa((float)pos1, coordz - 240 - 10 * i));
				agregar(new Trampa((float)pos2, coordz - 240 - 10 * i));

			}
			agr = false;
		}
	}
	frecuencia -= 1;
	if (frecuencia < 0) {//Frecuencia de creacion de trampas
		frecuencia = 250 / mult;//Mult para que dependa de la velocidad del ojo
		agr = true;//Cuando pasa el tiempo necesario, se permite crear una trampa
	}
}

void ListaTrampas::destructorTrampas(float coorz) {//Se destruyen las trampas cuando pasan por detras del ojo

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
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}