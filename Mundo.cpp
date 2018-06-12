#include "Mundo.h"
#include "Texto.h"
#include "Interaccion.h"
#include <iostream>
float Mundo::multip = 1;//Para construir adecuadamente las plataformas
Mundo::~Mundo() {
	delete bonus;
	monedas.destructorMonedas();
	obstaculos.destructorObstaculos();
	trampas.destructorTrampas();
}
void Mundo::dibuja(){
	personaje.dibuja();
	mapa.dibuja();
	monedas.dibuja();
	obstaculos.dibuja();
	trampas.dibuja();
	bonus->dibuja();
	Texto::imprimeMonedas(Texto::cadena(personaje.getContMonedas()),ojo.z-20);//Texto para el contador de monedas
	Texto::imprimeDistancia(Texto::cadena((int)ojo.z),velocidadOjo,ojo.z-20);//Texto para la distancia
	Texto::imprimeVidas(Texto::cadena(personaje.getVidas()),ojo.z-20);//Texto para las vidas
	portal.dibuja();//Tiene que ser el ultimo en dibujarse para que funcione bien la transparencia
	if (ojo.z < portal.getZ()) {
		static int a = 1;//Para cambiar texturas cuando se atraviesa portal
		portal.setZ(portal.getZ()-400);//Se mueve el portal cuando se sobrepasa
		PrismaRectangular::setMaterial(a);
		a++;
		if (velocidadOjo > -1.8f) {
			velocidadOjo -= 0.1f;//Cada vez que se aumenta en 0.1 la velocidad, se aumenta multip en 0.25
			multip += 0.25f;
		}//En realidad es un "multiplicador de frecuencia" de construccion del suelo, Siempre va a ser 1/4 del incremento de velocidadOjo por mátematica
		if (a == 3) a = 0;
	}

}

void Mundo::mueve() {//Las funciones están explicadas en sus respectivas clases
	ojo.z += velocidadOjo;//Velocidad del ojo
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
	Interaccion::redibujaMon(monedas, obstaculos);
	bool aux=Interaccion::cogeBonus(bonus, personaje);//Se utiliza el valor de retorno del impacto con bonus
	if (aux) {
		delete bonus;
		float pos = ETSIDI::lanzaDado(4);//Se borra un bonus y se genera otro en una posicion z mayor
		bonus= new Bonus(Vector3D(pos - 2.5f, 2.5f, ojo.z-840), Vector3D(pos - 1.5f, 3.5f, ojo.z-842), ETSIDI::lanzaMoneda());
	}
	if (personaje.getEscudo())
		personaje.finEscudo();
}

void Mundo::inicializa() {
	ojo.x = 0.0f;
	ojo.y = 4.5f;
	ojo.z = -10.0f;
	z_apunta = -100.0f;
	velocidadOjo = -0.4f;
	personaje.resetMonedas();
	Plataforma::setZ(0.0f);
	PrismaRectangular::setMaterial(0);//Hay que resetear los parametros static 
	multip = 1;
	float pos = ETSIDI::lanzaDado(4);
	bonus= new Bonus(Vector3D(pos - 2.5f, 2.5f, -440), Vector3D(pos - 1.5f, 3.5f, -442), ETSIDI::lanzaMoneda());
}

void Mundo::cambia() {
	mapa.cambia(multip);
	monedas.añadirMoneda(getOjo().z,multip);
	monedas.destructorMonedas(getOjo().z+10.0f);
	obstaculos.añadirObstaculo(getOjo().z, multip);
	obstaculos.destructorObstaculos(getOjo().z+10.0f);
	trampas.añadirTrampa(getOjo().z,multip);
	trampas.destructorTrampas(getOjo().z +60.0f);
	if (bonus->destruye(ojo.z)) {
		delete bonus;
		float pos = ETSIDI::lanzaDado(4);//Cuando se pasa el bonus por detras del ojo, se borra y se crea uno nuevo
		bonus= new Bonus(Vector3D(pos - 2.5f, 2.5f, ojo.z-540), Vector3D(pos - 1.5f, 3.5f, ojo.z-542), ETSIDI::lanzaMoneda());
	}
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
