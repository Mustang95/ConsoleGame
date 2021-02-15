#pragma once
#include "inimigo.h"
class lobo : public inimigo
{
private:
	int ReturnDamage()const;
	int ReturnHealAmount()const;
	int latido();
	
};

