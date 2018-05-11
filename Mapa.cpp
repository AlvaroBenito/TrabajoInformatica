#pragma once
#include "Mapa.h"
#include "Plataforma.h"
Mapa::Mapa(){
	float z = 50.0f;
	/*for (int i = 0; i < 3; i++) {
		camino[i].cambioZ(z);
		z -= 50.0f;
	}*/
}
void Mapa::dibuja() {
	for (int i = 0; i < 10; i++){
		camino[i].dibuja();
	}

}