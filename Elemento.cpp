#include "Elemento.h"
//En realidad las velocidades son la distancia recorrida cada 25ms, que es cuando se ejecuta el void OnTimer del main
Elemento::Elemento():aceleracionY(-0.20f) {
}

void Elemento::mueve(float vel) {
	velocidad.z = vel;
	velocidad.y -= aceleracionY * aceleracionY;
	posicion.x =posicion.x+ velocidad.x;
	posicion.y = posicion.y+velocidad.y;
	posicion.z = posicion.z+velocidad.z;

}

