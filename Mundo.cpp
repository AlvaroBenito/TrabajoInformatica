#include "Mundo.h"

void Mundo::dibuja(){
	mapa.dibuja();
	portal.dibuja();
	moneda.dibuja();
	if (ojo.z < portal.z) portal.z -= 280;
	
}

void Mundo::mueve() {
	static float signo = 1;
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
