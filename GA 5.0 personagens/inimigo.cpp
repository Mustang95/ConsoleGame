#include "inimigo.h"
inimigo::inimigo(){
	nome = "BBB";
	hp = 100;
	mp = 0;
	def = 2;
	evasion = 2;
	hitRate = 2;
	speed = 2;
	luck = 2;

}
inimigo::~inimigo(){}

int inimigo::ataque(){
	// Returns damage hit for the player. Uses random number to select enemy's move.

	int selector = rand() % 9;
	switch (selector){
	case 0: case 1:
		// 2/9 chance of risk attacking.
		return atqGenerico();
		break;
	case 2: case 3:
		// 2/9 chance of healing.
		heal();
		return 0;
		break;
	case 4: case 5: case 6: case 7: case 8:
		// 5/9 chance of generically attacking.
		return atqGenerico()/*GenericAttack()*/;
		break;
	default:
		// Returns 0 damage in case selector goes wrong.
		return 0;
		break;
	}
}

vector<int> inimigo::getdrops(){
	vector<int> drops;

	for (int i = 0; i < 3; i++){
		drops.push_back(returnItemDrop(i));
	}
	return drops;
}

int inimigo::atqGenerico()const{
	int damage = ReturnDamage();

	cout << " ataque! causou ";
	cout << " de dano! " << endl << endl;
	return damage;

}

int inimigo::returnItemDrop(int item){
	int arrowSelect = rand() % 6;
	int potionSelect = rand() % 10;
	//arrow, potions
	switch (item)
	{
	case 0:
		if (arrowSelect <= 1)
			return 0;
		else if (arrowSelect == 2 || arrowSelect == 3)
			return 3;
		else
			return 5;
	case 1: case 2:
		if (potionSelect == 0)
			return 1;
		else if (potionSelect == 1)
			return 2;
		else
			return 0;
	default:
		return 0;
		break;
	}
}


//////////////////

int inimigo::ReturnDamage()const{
	return 0;
}
int inimigo::ReturnHealAmount()const{
	return 0;
}