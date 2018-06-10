#include <stdlib.h>
#include "ListaBonus.h"
#include "ETSIDI.h"

ListaBonus::ListaBonus():numero(0) {
	for (int i = 0; i < MAX_BONUS; i++) {
		lista[i] = NULL;
	}
}
bool ListaBonus::agregar(Bonus *e)
{
	if (numero<MAX_BONUS)
		lista[numero++] = e;
	else
		return    false;
	return    true;
}

void ListaBonus::dibuja()
{
	for (int i = 0; i<numero; i++)
		lista[i]->dibuja();
}

void ListaBonus::añadirBonus(float coordz, float mult) {
	static float frecuencia = 40;
	frecuencia -= 1;
	if (frecuencia < 0) {
		float pos = (float)ETSIDI::lanzaDado(4);
		Bonus *aux = new Bonus(Vector3D(pos-2.5f,2.5f,coordz - 240), Vector3D(pos - 1.5f, 3.5f, coordz - 242),ETSIDI::lanzaMoneda());
		agregar(aux);
		int num = ETSIDI::lanzaDado(5);
		frecuencia = (num + 3) * 40 / mult;
	}

}
void ListaBonus::destructorBonus(float coordz) {

	for (int i = 0; i <numero; i++) {
		if (coordz < lista[i]->getP1().z-10) {
			delete lista[i];
			numero--;
			for (int j = i; j < numero; j++)
				lista[j] = lista[j + 1];
		}
	}
}
void ListaBonus::eliminar(int index) {
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}