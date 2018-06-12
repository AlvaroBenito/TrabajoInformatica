#pragma once
#include "PrismaRectangular.h"
//Esta clase crea objetos tipo bonus, que son prismas rectangulares a cierta altura para que el personaje los coja
class Bonus :public PrismaRectangular {
	bool tipo;//Tipo false: Vida, tipo true: escudo
public:
	~Bonus();
	Bonus(Vector3D a,Vector3D b,bool tip);
	void dibuja();
	bool destruye(float z);//Método para saber si se puede destruir o no un bonus en funcion de su posicion en el eje z
	friend class Interaccion;
};