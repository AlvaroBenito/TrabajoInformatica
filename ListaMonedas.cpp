#include "ListaMonedas.h"
#include <cstdlib>

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
	for (int i = 0; i<numero; i++)
		lista[i]->rotar();
}

void ListaMonedas::generadorMonedas(float coordz){

	//static int coorz = -40;
	//coorz -= 5;
	float coorinicial = coordz;
	if(numero==0){
		for (float i = coordz; i > coordz - 270; i = i - 10) {
			//if (mod % 20 == 0) {
			Moneda* aux = new Moneda(rand()%3-1, 1.7, i);
			agregar(aux);
		}
		}
	
	
	
}

void ListaMonedas::descructorMonedas(float coorz) {

	for (int i = 0; i <numero; i++) {
		if (coorz < lista[i]->posicion.z) {
			delete lista[i];
			numero--;
			for (int j = i; j < numero; j++)
				lista[j] = lista[j + 1];
			
		}
	}
}