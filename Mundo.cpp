#include "Mundo.h"
#include "glut.h"
#include <math.h>


void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	
	caja.dibuja();
	hombre.dibuja();
	disparo.dibuja();
	plataforma.dibuja();
	bonus.dibuja();
	esferas.dibuja();

}

void Mundo::mueve()
{
	hombre.mueve(0.025f);
	bonus.mueve(0.025f);
	disparo.mueve(0.025f);
	esferas.mueve(0.025f);
	esferas.rebote();
	esferas.rebote(plataforma);
	esferas.rebote(caja);
	Esfera    *aux = esferas.colision(esferas.~ListaEsferas);
	if (aux != 0)//si alguna esfera ha chocado 
		esferas.eliminar(aux);
	Interaccion::rebote(hombre, caja);
}

void Mundo::inicializa()
{
	x_ojo=0;
	y_ojo=7.5;
	z_ojo=30;

	Esfera *e1 = new Esfera(1, 2, 4, 5, 15);
	e1->setColor(200, 0, 0);
	esferas.agregar(e1);    //esfera    
	Esfera *e2 = new Esfera(2, -2, 4, -5, 15);
	e2->setColor(255, 255, 255);
	esferas.agregar(e2);    //esfera2    	

	bonus.setPos(5.0f,5.0f);
	disparo.setPos(-5.0f,0.0f);
	plataforma.setPos(-5.0f,9.0f,5.0f,9.0f);

	for (int i = 0; i<6; i++)
	{
		Esfera* aux = new Esfera(0.75 + i * 0.25, i, 1 + i, i, i);
		esferas.agregar(aux);
	}
	
}

void Mundo::tecla(unsigned char key)
{

}


void Mundo::teclaEspecial(unsigned char key)
{
	switch(key)
	{
	case GLUT_KEY_LEFT:
		hombre.setVel (-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.setVel (5.0f, 0.0f);
		break;
	}
}

Mundo::~Mundo()
{
	esferas.destruirContenido();
}