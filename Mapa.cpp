#pragma once
#include "Mapa.h"
#include "Plataforma.h"
Mapa::Mapa(){
	camino = 0;
	n = 0;
	inicializa = false;
}
void Mapa::dibuja() {                     //funcion para dibujar las 17 plataformas(17 porque se deja de ver la construccion al final de las plataformas)
	if (inicializa == false) {            //Hay que primero dibujar 17 para iniciar, y luego la funcion cambia se encargar� de modificar sus posiciones
		camino = new Plataforma[17];
		camino->z = -10 * (float)++n;
	}
	for (int i = 0; i < 17; i++){
		camino[i].dibuja();
	}
	inicializa = true;
}
void Mapa::cambia() {//funcion para destruir y volver a crear las plataformas:
					 //El objetivo es que el mapa vaya avanzando y que cuando se a�adan texturas, de una sensacion de avance del personaje
	static int cuenta = 24;//Se ajusta la creacion del nuevo mapa a la velocidad del personaje
	if (cuenta == 0) {
		camino->z = -10 * (float)(++n);
		delete[]camino;
		camino = new Plataforma[17];
		cuenta = 25;
	}
	cuenta--;
}