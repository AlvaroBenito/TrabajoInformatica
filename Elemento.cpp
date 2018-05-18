#include "elemento.h"



void Elemento::mueve() {
	posicion.z = posicion.z - velocidad;
}

void Elemento::setPosZ(float z) {
	posicion.z = z;
}