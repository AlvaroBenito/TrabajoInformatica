#include "Mundo.h"

void Mundo::dibuja(){
	//moneda.dibuja();
	mapa.dibuja();
}

void Mundo::mueve() {
	ojo.z -= 0.4f;
	z_apunta -= 0.4f;

}

void Mundo::inicializa() {
	ojo.x = 0.0f;
	ojo.y = 4.5f;
	ojo.z = -10.0f;
	z_apunta = -100.0f;

}
Vector3D Mundo::getOjo() {
	return ojo;
}
float Mundo::getZapunta() {
	return z_apunta;
}
void Mundo::cambia() {
	mapa.cambia();
}
