#pragma once
#include "inimigo.h"
class demonio : public inimigo
{
private:
	int ReturnDamage()const;
	int ReturnHealAmount()const;
	int chamaInfernal();
	int chamasNegras();
	int curaInfernal();
};

