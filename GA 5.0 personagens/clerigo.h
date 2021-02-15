#pragma once
#include "jogador.h"
class clerigo : public jogador
{

private:
	int curar();
	int ressucitar();
	int ReturnDamage()const;
	int ReturnHealAmount()const;
};

