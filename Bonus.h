#pragma once
#include "Elemento.h"
class Bonus :public Elemento {

	bool tipo;//Indica el tipo de bonus.

public:
	Bonus();
	virtual ~Bonus();
	void dibuja();
};