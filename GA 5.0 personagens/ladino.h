#pragma once
#include "jogador.h"
class ladino : public jogador
{
private:
	int ReturnDamage()const;
	int ReturnHealAmount()const;
	int apunhalar();
	int floreio();
	int esquivar();
};