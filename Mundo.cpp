#include "Mundo.h"
#include "Interaccion.h"
float Mundo::multip = 1;//Para construir adecuadamente las plataformas
void Mundo::dibuja(){
	personaje.dibuja();
	mapa.dibuja();
	monedas.dibuja();
	portal.dibuja();//Tiene que ser el ultimo en dibujarse para que funcione bien la transparencia
	if (ojo.z < portal.getZ()) {
		static int a = 1;//Para cambiar texturas cuando se atraviesa portal
		portal.setZ(portal.getZ()-280);
		PrismaRectangular::setMaterial(a);
		a++;
		velocidadOjo -= 0.1f;
		multip+=0.25f;//En realidad es un "multiplicador de frecuencia" de construccion del suelo, Siempre va a ser 1/4 del incremento de velocidadOjo por mátematica
		if (a == 3) a = 0;
	}

}

void Mundo::mueve() {
	ojo.z += velocidadOjo;
	personaje.mueve(velocidadOjo);
	z_apunta += velocidadOjo;
	monedas.rotar();
	monedas.cogerMonedas(personaje);
	Interaccion::reboteSuelo(mapa.getPlat(0).getSuelo(), personaje);
	Interaccion::mueveCentro(mapa.getPlat(0).getSuelo(), personaje);
	Interaccion::choqueParedes(mapa.getPlat(0).getParedDer(),mapa.getPlat(0).getParedIzq(),personaje);
}

void Mundo::inicializa() {
	ojo.x = 0.0f;
	ojo.y = 4.5f;
	ojo.z = -10.0f;
	z_apunta = -100.0f;
	velocidadOjo = -0.4f;
	Vector3D pos(0.0f, 1.7f, -40.0f);
	Vector3D pos2(1.0f, 1.7f, -40.0f);
	Vector3D pos3(-1.0f, 1.7f, -40.0f);
	monedas.generadorMonedas(getOjo().z);
}
Vector3D Mundo::getOjo() {
	return ojo;
}
float Mundo::getZapunta() {
	return z_apunta;
}
void Mundo::cambia() {
	mapa.cambia(multip);
	monedas.añadirMoneda(getOjo().z,multip);
	monedas.descructorMonedas(getOjo().z-10.0f);
	
}
void Mundo::tecla(unsigned char key) {
	if (key == 'a') personaje.gira(false);
	if (key == 'd') personaje.gira(true); 
	if (key == ' ') personaje.salta();
}