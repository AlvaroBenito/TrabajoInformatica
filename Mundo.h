#pragma once
#include "Mapa.h"
#include "Bonus.h"
#include "Moneda.h"
#include "Personaje.h"

class Mundo
{

	Mapa mapa;
	Bonus bonus;
	Moneda moneda;
	Personaje personaje;
	float x_ojo;
	float y_ojo;
	float z_ojo;

public:

	
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();
	
	
};

