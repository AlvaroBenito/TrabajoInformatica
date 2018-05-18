#pragma once
#include "Vector3D.h"
//Clase base para hacer basicamente todos los elementos moviles, que son: Personaje, Moneda, Bonificacion, Obstaculo,etc
class Elemento {
//protected://Protected para que lo use solo las clases heredadas y luego ponemos friend las clases para las interacciones y ese rollo
	

public:
	
	Vector3D posicion;
	float velocidad;
	void mueve();//En obstaculos no se usa necesariamente
	void setPosZ(float z);
};