#include "Mundo.h"
#include "Interaccion.h"
float Mundo::multip = 1;//Para construir adecuadamente las plataformas
void Mundo::dibuja(){
	mapa.dibuja();
	portal.dibuja();
	moneda.dibuja();
	moneda2.dibuja();
	moneda3.dibuja();
	monedas.dibuja();
	personaje.dibuja();
	if (ojo.z < portal.z) {
		static int a = 1;//Para cambiar texturas cuando se atraviesa portl
		portal.z -= 280;
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
	moneda.rotar();
	moneda2.rotar();
	moneda3.rotar();
	monedas.rotar();
	Interaccion::reboteSuelo(mapa.getSuelo(0).getPrisma(), personaje);
}

void Mundo::inicializa() {
	ojo.x = 0.0f;
	ojo.y = 4.5f;
	ojo.z = -10.0f;
	z_apunta = -100.0f;
	velocidadOjo = -0.4f;
	Vector3D pos(0.0f, 1.7f, -40.0f);
	moneda.setPos(pos);
	Vector3D pos2(1.0f, 1.7f, -40.0f);
	moneda2.setPos(pos2);
	Vector3D pos3(-1.0f, 1.7f, -40.0f);
	moneda3.setPos(pos3);

	

}
Vector3D Mundo::getOjo() {
	return ojo;
}
float Mundo::getZapunta() {
	return z_apunta;
}
void Mundo::cambia() {
	mapa.cambia(multip);
	//monedas.generadorMonedas();
	//monedas.descructorMonedas(getOjo().z-10.0f);
	
}
