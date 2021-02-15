#pragma once
#include "inimigo.h"
class vampiro : public inimigo
{
private:
	int ReturnDamage()const;
	int ReturnHealAmount()const;
	int mordida();
	int pocaDeSangue();
};