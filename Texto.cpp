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
void Texto::imprimeMonedas(char *txt,float z) {
	char m[8] = "Monedas";
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("Fuentes/Bitwise.ttf",20);
	printxyz(m,4,-3,z);
	printxyz(txt,7,-3,z);
}
void Texto::imprimeVidas(char *txt, float z) {
	char m[6] = "Vidas";
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("Fuentes/Bitwise.ttf", 20);
	printxyz(m, -7, 8, z);
	printxyz(txt, -4, 8, z);
}
void Texto::imprimeDistancia(char *txt,float vel,float z) {
	char m[10] = "Distancia";
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("Fuentes/Bitwise.ttf", 20);
	printxyz(m,-7,-3,z);
	printxyz(txt,-4,-3,z);

}
char* Texto::cadena(int num){
	std::stringstream s;//Variable tipo stringstream
	s << num;
	char *y = new char[s.str().length()+1];//s.str() es una especie de cast para usar s como string
	std::strcpy(y,s.str().c_str());//s.str().c_str() pasa el string a char*
	return y;
}
