#include "Mundo.h"

void Mundo::dibuja(){

	moneda.dibuja();

}

void Mundo::mueve(float t) {
	ojo.z -= 0.5f;
	z_apunta -= 0.5f;
}

void Mundo::inicializa() {

	ojo.x = 0.0f;
	ojo.y = 4.5f;
	ojo.z = -55.0f;
	z_apunta = -100.0f;

}
Vector3D Mundo::getOjo() {
	return ojo;
}
float Mundo::getZapunta() {
	return z_apunta;
}
