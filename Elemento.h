#pragma once
#include "Vector3D.h"
//Clase base utilizada para no tener que reescribir los vectores de posicion, velocidad y aceleracion en todas sus derivadas
//Tambien sirve para generalizar el movimiento, aunque solo Personaje lo utiliza
class Elemento {
protected:
	Vector3D posicion;
	Vector3D velocidad;
	float aceleracionY;
public:
	Elemento();
	void mueve(float vel);
	void setPosZ(float z);//Funcion de interfaz para cambiar posicion.z
	Vector3D getPos();
};
inline Vector3D Elemento::getPos() {
	return posicion;
}
inline void Elemento::setPosZ(float z) {
	posicion.z = z;
}
