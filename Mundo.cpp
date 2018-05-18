#include "Mundo.h"

void Mundo::dibuja(){
	mapa.dibuja();
	portal.dibuja();
	moneda.dibuja();
	moneda2.dibuja();
	moneda3.dibuja();

	if (ojo.z < portal.z) portal.z -= 280;
	
}

void Mundo::mueve() {
	static float signo = 1;
	ojo.z -= 0.4f;
	z_apunta -= 0.4f;
	moneda.rotar();
	moneda2.rotar();
	moneda3.rotar();

}

void Mundo::inicializa() {
	ojo.x = 0.0f;
	ojo.y = 4.5f;
	ojo.z = -10.0f;
	z_apunta = -100.0f;
	
	Vector3D pos(0, 1.7, -40);
	moneda.setPos(pos);
	Vector3D pos2(1, 1.7, -40);
	moneda2.setPos(pos2);
	Vector3D pos3(-1, 1.7, -40);
	moneda3.setPos(pos3);

	
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
