#pragma once
#include "jogador.h"
class guerreiro : public jogador
{
private:
	int superdef();
	int superatq();
	int ReturnDamage()const;
	int ReturnHealAmount()const;
};

