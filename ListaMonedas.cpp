#include <stdlib.h>
#include "ListaMonedas.h"
#include <cstdlib>
#include "ETSIDI.h"
ListaMonedas::ListaMonedas()
{

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

void ListaMonedas::generadorMonedas(float coordz){
	float pos = (float)ETSIDI::lanzaDado(4) - 2;//como la distancia entre cada carril es 1, se aprovecha para obtener facilmente uno de los numeros: -1,0,1 de los tres carriles
		for (float i = coordz-50; i > coordz - 85; i = i - 5) {
			Moneda* aux = new Moneda(pos, 1.4f, i);
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
			agr = true;
		}
	}
}
void ListaMonedas::añadirMoneda(float coorz) {
	static int grupo = 7;
	static float pos = (float)ETSIDI::lanzaDado(4)-2;
	if (agr) {
		Moneda *aux = new Moneda(pos, 1.4f, coorz - 120);
		agregar(aux);
		agr = false;
		grupo --;
	}
	if (grupo == 0) {
		pos = (float)ETSIDI::lanzaDado(4)-2;
		grupo = 7;
	}
}