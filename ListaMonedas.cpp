#include <stdlib.h>
#include "ListaMonedas.h"
#include <cstdlib>
#include "ETSIDI.h"
#include "Interaccion.h"
#include "MonedaEspecial.h"
ListaMonedas::ListaMonedas():numero(0)
{
	for (int i = 0; i < MAX_MONEDAS; i++)//Inicializacion de los punteros a NULL
		lista[i] = NULL;
}

ListaMonedas::~ListaMonedas()
{
}

bool ListaMonedas::agregar(Moneda *moneda)//Metodo para crear monedas de forma correcta
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
void ListaMonedas::rotar()//Funcion para aumentar el angulo de rotacion de la moneda
{
	Moneda::sumaAnguloRot(5.0f);
}
void ListaMonedas::cogerMonedas(Personaje p) {//Funcion para coger las monedas utilizando la interaccion cogerMoneda
	bool aux = false;
	for (int i = 0; i < numero; i++) {
		aux=Interaccion::cogerMoneda(*lista[i], p);//si hay colision, devuelve true
		if (aux) {
			ETSIDI::play("Sound/Moneda.mp3");
			eliminar(i);
		}
		
	}
}
void ListaMonedas::destructorMonedas(float coorz) {//Destruye las monedas si se quedan por detras

	for (int i = 0; i <numero; i++) {
		if (coorz < lista[i]->getPos().z) {
			delete lista[i];
			numero--;
			for (int j = i; j < numero; j++)
				lista[j] = lista[j + 1];
		}
	}
}
void ListaMonedas::añadirMoneda(float coorz,float mult) {//Genera correctamente los grupos de monedas de forma separada
	static int grupo = 7;//Se generan grupos de 7 monedas
	static float pos = (float)ETSIDI::lanzaDado(4) - 2;
	static float cuentaMon = 50;
	if (agr) {//Si se pueden agregar monedas
		bool monedaEsp = false;
		int num = ETSIDI::lanzaDado(8);//Se genera un numero aleatorio para saber si la moneda va a ser especial o no
		if (num == 1) monedaEsp = true;
		if (monedaEsp) {
			Moneda *aux1 = new MonedaEspecial(pos, 0.96f, coorz - 120);
			agregar(aux1);
		}
		else {
			Moneda *aux2 = new Moneda(pos, 0.96f, coorz - 120);
			agregar(aux2);
		}
		agr = false;//Despues de crear una moneda, se espera para poder crear la siguiente
		grupo--;
	}
	if (grupo == 0) {//Cuando ya se han creado 7 monedas, se espera al siguiente grupo de monedas
		pos = (float)ETSIDI::lanzaDado(4) - 2;//Genera el carril donde se dibujará el siguiente grupo
		grupo = 7;//Reinicia la cuenta del grupo siguiente
		agr = false;//No permite de momento crear monedas hasta que sea true
		cuentaMon = 150.0f/mult;//Tiempo desde que muere un grupo de monedas hasta que aparece otro basado en la velocidad del ojo(mult)
	}
	cuentaMon--;
	if (cuentaMon < 0 && grupo != 0) {//Cuando se acaba el tiempo para crear monedas entre grupo y grupo, se vuelve a crear otro grupo
		cuentaMon = 12.0f/mult;//Frecuencia de creacion de las monedas dentro del mismo grupo de monedas
		agr = true;//Cuando pasa el tiempo necesario, se permite crear una moneda
	}
}
void ListaMonedas::eliminar(int index) {//Funcion para poder eliminar monedas de forma correcta
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaMonedas::destructorMonedas() {
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
	
}