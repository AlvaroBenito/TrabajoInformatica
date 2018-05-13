#pragma once
#include "Mapa.h"
#include "Plataforma.h"
Mapa::Mapa(){
	camino = 0;
	n = 0;
	inicializa = false;
}
void Mapa::dibuja() {                     //funcion para dibujar las 15 plataformas(15 porque visualmente queda mejor)
	if (inicializa == false) {            //Hay que primero dibujar 15 para iniciar, y luego la funcion cambia se encargará de modificar sus posiciones
		camino = new Plataforma[25];
		camino->z = -10 * (float)++n;
	}
	for (int i = 0; i < 25; i++){
		camino[i].dibuja();
	}
	inicializa = true;

}
void Mapa::cambia() {//funcion para destruir y volver a crear las plataformas:
					 //El objetivo es que el mapa vaya avanzando y que cuando se añadan texturas, de una sensacion de avance del personaje
	static int cuenta = 24;
	if (cuenta == 0) {
		camino->z = -10 * (float)(++n);
		delete[]camino;
		camino = new Plataforma[25];
		cuenta = 25;
	}
	cuenta--;
}