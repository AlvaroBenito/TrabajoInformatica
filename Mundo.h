#pragma once
#include "Mapa.h"
#include "Bonus.h"
#include "Moneda.h"
#include "Personaje.h"
#include "Plataforma.h"
#include "Vector3D.h"
#include "Portal.h"
#include "ListaMonedas.h"

class Mundo
{

	Mapa mapa;
	Moneda moneda;
	Moneda moneda2, moneda3;
	ListaMonedas monedas;
	Bonus bonus;
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
	
};

