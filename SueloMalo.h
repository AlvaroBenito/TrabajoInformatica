#pragma once
#include "Plano.h"
class SueloMalo :public Plano {
public:
	SueloMalo();
	SueloMalo(float coordx, float coordz);
	~SueloMalo();
	void dibuja();
};