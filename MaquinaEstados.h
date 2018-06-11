#pragma once
#include "Mundo.h"

class MaquinaEstados
{
public:
	MaquinaEstados();
	~MaquinaEstados();
	
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void    mueve();
	void    dibuja();
	void cambia();
	Vector3D getOjo();
	float getZapunta();
protected:
	Mundo    *mundo;
	enum Estado{INICIO,JUEGO, GAMEOVER,PAUSA};
	Estado estado;
};
inline Vector3D MaquinaEstados::getOjo() {
	return mundo->getOjo();
}
inline float MaquinaEstados::getZapunta() {
	return mundo->getZapunta();
}

