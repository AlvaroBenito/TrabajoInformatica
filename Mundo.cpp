#include "Mundo.h"
#include "Texto.h"
#include "Interaccion.h"
float Mundo::multip = 1;//Para construir adecuadamente las plataformas
void Mundo::dibuja(){
	personaje.dibuja();
	mapa.dibuja();
	monedas.dibuja();
	obstaculos.dibuja();
	trampas.dibuja();
	bonus.dibuja();
	Texto::imprimeMonedas(Texto::cadena(personaje.getContMonedas()),ojo.z-20);
	Texto::imprimeDistancia(Texto::cadena((int)ojo.z),velocidadOjo,ojo.z-20);
	Texto::imprimeVidas(Texto::cadena(personaje.getVidas()),ojo.z-20);
	portal.dibuja();//Tiene que ser el ultimo en dibujarse para que funcione bien la transparencia
	if (ojo.z < portal.getZ()) {
		static int a = 1;//Para cambiar texturas cuando se atraviesa portal
		portal.setZ(portal.getZ()-280);
		PrismaRectangular::setMaterial(a);
		a++;
		velocidadOjo -= 0.1f;
		multip+=0.25f;//En realidad es un "multiplicador de frecuencia" de construccion del suelo, Siempre va a ser 1/4 del incremento de velocidadOjo por mátematica
		if (a == 2) a = 0;
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
	Interaccion::condicionDibujo(trampas, obstaculos);
	Interaccion::reboteObstaculo(obstaculos, personaje);
	Interaccion::colisionTrampas(trampas, personaje);
	Interaccion::cogeBonus(bonus, personaje);
}

void Mundo::inicializa() {
	ojo.x = 0.0f;
	ojo.y = 4.5f;
	ojo.z = -10.0f;
	z_apunta = -100.0f;
	velocidadOjo = -0.4f;
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
	obstaculos.añadirObstaculo(getOjo().z, multip);
	obstaculos.destructorObstaculos(getOjo().z-10.0f);
	trampas.añadirTrampa(getOjo().z,multip);
	trampas.descructorTrampas(getOjo().z +200);
	bonus.añadirBonus(getOjo().z, multip);
	bonus.destructorBonus(getOjo().z-10.0f);
	
	
}
void Mundo::tecla(unsigned char key) {
	if (key == 'a') personaje.gira(false);
	if (key == 'd') personaje.gira(true); 
	if (key == ' ') personaje.salta();
}

void Mundo::teclaEspecial(unsigned char key) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		personaje.gira(false);
		break;
	case GLUT_KEY_RIGHT:
		personaje.gira(true);
		break;
	case GLUT_KEY_UP:
		personaje.salta();
		break;

	}
}