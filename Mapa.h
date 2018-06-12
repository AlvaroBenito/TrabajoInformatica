#pragma once
#include "PrismaRectangular.h"
#include "Plataforma.h"
#include "Portal.h"
//Clase para dibujar el mapa, que tendrá suelo, paredes externas, e incluso podriamos meter los obstaculos aqui en vez de en la clase Elemento
class Mapa {
	Plataforma *camino;//Camino del suelo
	bool inicializa;//Variable para crear por primera vez el suelo
	int n;//Variable para ir variando la posicion del suelo
public:
	Mapa();
	void dibuja();
	void cambia(float mult);//Metodo para cambiar la localizacion del suelo
	Plataforma getPlat(int i);
};
inline Plataforma Mapa::getPlat(int i) {
	Plataforma plat;
	if (camino != 0)//Solo retorna el camino si el puntero no señala a 0
		return camino[i];
	else return plat;
}
