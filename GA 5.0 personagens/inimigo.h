#pragma once
#include <vector>
#include "atributos.h"
using namespace std;
class inimigo : public atributos
{
public:
	inimigo();
	~inimigo();
	int ataque();
	vector<int> getdrops();
	int returnExp();
protected:
	int atqGenerico()const;
	virtual int ReturnDamage()const;
	virtual int ReturnHealAmount()const;

	int returnItemDrop(int);
};

