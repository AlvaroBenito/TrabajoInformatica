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
#include "ListaBonus.h"

class Mundo
{
	Mapa mapa;
	ListaMonedas monedas;
	ListaObstaculos obstaculos;
	ListaTrampas trampas;
	ListaBonus bonus;
	Personaje personaje;
	Portal portal;
	Vector3D ojo;
	float z_apunta;
	float velocidadOjo;
	static float multip;
public:
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();
	Vector3D getOjo();
	float getZapunta();
	void cambia();
	int getVidas() { return personaje.getVidas(); }
};

