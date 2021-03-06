#define _CRT_SECURE_NO_WARNINGS//El strcpy sin esto no funciona
#include "Texto.h"
#include "ETSIDI.h"

void Texto::printxyz(char *txt, float x, float y, float z) {
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glTranslatef(x,y,z);
	ETSIDI::print(txt);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glTranslatef(-x,- y,- z);
	glPopMatrix();
}
void Texto::imprimeMonedas(char *txt,float z) {//Funcion para imprimir las monedas en mundo
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("Fuentes/Bitwise.ttf",20);
	printxyz((char*)"Monedas",4,-3,z);//Puesto que "Monedas" es const char*, se soluciona el problema haciendo un cast,
	printxyz(txt, 7, -3, z);		  //ya que printx solo lee char*. Lo mismo ocurre con los m�todos de abajo
}
void Texto::imprimeVidas(char *txt, float z) {//Funcion para imprimir las vidas en mundo
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("Fuentes/Bitwise.ttf", 20);
	printxyz((char*)"Vidas", -7, 8, z);
	printxyz(txt, -4, 8, z);
}
void Texto::imprimeDistancia(char *txt,float vel,float z) {//Funcion para imprimir la distancia en mundo
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("Fuentes/Bitwise.ttf", 20);
	printxyz((char*)"Distancia",-7,-3,z);
	printxyz(txt,-4,-3,z);

}
char* Texto::cadena(int num){//Esta funcion permite transformar un numero en una cadena de caracteres haciendo uso de memoria dinamica
	std::stringstream s;//Variable tipo stringstream
	s << num;
	char *y = new char[s.str().length()+1];//s.str() permite usar un flujo stringstream como si fuera un string
	std::strcpy(y,s.str().c_str());//s.str().c_str() pasa el string a char*
	return y;
}
