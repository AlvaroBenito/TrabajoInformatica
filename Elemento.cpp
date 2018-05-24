#include "Elemento.h"
//En realidad las velocidades son la distancia recorrida cada 25ms, que es cuando se ejecuta el void OnTimer del main
Elemento::Elemento() {
}

void Elemento::mueve(float vel) {
	velocidad.z = vel;
	posicion.x += velocidad.x;
	posicion.y += velocidad.y;
	posicion.z += velocidad.z;
}

void Elemento::setPosZ(float z) {
	posicion.z = z;
}