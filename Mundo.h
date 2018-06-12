#pragma once
#include "Mapa.h"
#include "Bonus.h"
#include "Personaje.h"
#include "Plataforma.h"
#include "Vector3D.h"
#include "Portal.h"
#include "ListaMonedas.h"
#include "ListaObstaculos.h"
#include "Interaccion.h"
#include "Texto.h"
#include "glut.h"
#include "ListaTrampas.h"

class Mundo
{
	Mapa mapa;
	ListaMonedas monedas;
	ListaObstaculos obstaculos;
	ListaTrampas trampas;
	Bonus *bonus;//al solo poder haber un bonus a la vez en el mapa, no se necesita una lista
	Personaje personaje;
	Portal portal;//Ocurre lo mismo que con el bonus, pero tiene un comportamiento distinto
	Vector3D ojo;
	float z_apunta;
	float velocidadOjo;
	static float multip;//Valor que va a la coordinado con la velocidad del ojo para el calculo de las frecuencias dentro de otras clases
public:
	~Mundo();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();
	Vector3D getOjo();
	float getZapunta();
	void cambia();
	Personaje getPers();
};
inline Vector3D Mundo::getOjo() {
	return ojo;
}

inline float Mundo::getZapunta() {
	return z_apunta;
}
inline Personaje Mundo::getPers() {
	return personaje;
}