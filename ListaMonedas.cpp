#include "ListaMonedas.h"


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

void ListaMonedas::generadorMonedas(){

	static int coorz=-40;
	coorz -= 5;
	int mod=coorz;

	if (mod % 20 == 0) {
		Moneda* aux = new Moneda(0, 1.7, coorz);
		agregar(aux);
	}
	

	
}

void ListaMonedas::descructorMonedas(float coorz) {

	for (int i = 0; i <numero; i++) {
		if (coorz < lista[i]->posicion.z) {
			delete lista[i];
			numero--;
		}
	}
}