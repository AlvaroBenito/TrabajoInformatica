#include "ListaMonedas.h"


ListaMonedas::ListaMonedas()
{

}

ListaMonedas::~ListaMonedas()
{

}

bool ListaMonedas::agregar(Moneda *e)
{
	if (numero<MAX_MONEDAS)
		lista[numero++] = e;
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