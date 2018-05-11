#pragma once
#include <math.h>
//En funcion de lo que necesitemos, vamos sobrecargando operadores e incluyendo funciones parecidas al pang de unitario() o modulo()
class Vector3D {
public:
	float x;
	float y;
	float z;
	Vector3D(float x1=0.0f, float y1=0.0f, float z1=0.0f);
	
	float modulo();
	Vector3D unitario();		   
	Vector3D operator - (Vector3D &);	
	Vector3D operator + (Vector3D &);	
	float operator *(Vector3D &);	 	
	Vector3D operator *(float);	
	Vector3D operator /(float);
	Vector3D operator + (float x1);//Operacion sumar al eje x
	Vector3D operator - (float x1);
};
