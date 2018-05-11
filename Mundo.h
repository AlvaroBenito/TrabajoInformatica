#pragma once
#include "Mapa.h"
#include "Bonus.h"
#include "Moneda.h"
#include "Personaje.h"
#include "Plataforma.h"
#include "Vector3D.h"
class Mundo
{
	Mapa mapa;
	Bonus bonus;
	Moneda moneda;
	Personaje personaje;
	Vector3D ojo;
	float z_apunta;

public:
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void mueve(float t);
	void dibuja();
	Vector3D getOjo();
	float getZapunta();
	
};

