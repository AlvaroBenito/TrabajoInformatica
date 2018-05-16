#include "elemento.h"


Elemento::Elemento() {
	
}

Elemento::Elemento(Vector3D pos, float vel) {
	posicion = pos;
	velocidad = vel;
}

void Elemento::mueve() {
	posicion.z = posicion.z + velocidad;
}


