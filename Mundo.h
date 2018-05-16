#include "Caja.h"	
#include "Hombre.h"	
#include "Esfera.h"	
#include "Bonus.h"	
#include "Disparo.h"
#include "Interaccion.h"
#include "ListaEsferas.h"

class Mundo
{

	Disparo disparo;
	Hombre hombre;
	Caja caja;
	Bonus bonus;
	Pared plataforma;
	ListaEsferas esferas;
	float x_ojo;
	float y_ojo;
	float z_ojo;
public: 

	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	~Mundo();
};
