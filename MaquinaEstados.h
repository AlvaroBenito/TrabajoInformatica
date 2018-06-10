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
	Vector3D getOjo() { return mundo->getOjo(); }
	float getZapunta() { return mundo->getZapunta(); }
protected:
	Mundo    *mundo;
	enum Estado{INICIO,JUEGO, GAMEOVER};
	Estado estado;
};

