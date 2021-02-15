#pragma once
#include "jogador.h"
class mago : public jogador
{
private:
	int canhaoM();
	int BolaDFogo();
	int EscudoM();
	int relampago();
	int ReturnDamage()const;
	int ReturnHealAmount()const;
};

