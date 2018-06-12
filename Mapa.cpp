#pragma once
#include "Mapa.h"
#include "Plataforma.h"
Mapa::Mapa(){
	camino = 0;
	n = -1;
	inicializa = false;
}
void Mapa::dibuja() {         //funcion para dibujar las 18 plataformas(18 porque se deja de ver la construccion al final de las plataformas)
	if (inicializa == false) {//Hay que primero dibujar 18 para iniciar, y luego la funcion cambia se encargar� de modificar sus posiciones
		camino = new Plataforma[18];
		camino->setZ(-10 * (float)++n);//Incrementamos n para que cada vez se construyan mas alejadas en el eje z
	}
	for (int i = 0; i < 18; i++){
		camino[i].dibuja();
	}
	inicializa = true;
}
void Mapa::cambia(float mult) {//funcion para destruir y volver a crear las plataformas:
							   //El objetivo es que el mapa vaya avanzando y que cuando se a�adan texturas, de una sensacion de avance del personaje
							   //Si el suelo se moviera con el personaje, parecer�a que est� quieto
	static float cuenta = 25;
	if (cuenta < 0) {
		camino->setZ(-10 * (float)(++n));
		delete[]camino;//Se destruyen las plataformas para luego volver a crearlas en otra posici�n
		camino = new Plataforma[18];
		cuenta += 25/mult;
	}
	cuenta-=1;
}

