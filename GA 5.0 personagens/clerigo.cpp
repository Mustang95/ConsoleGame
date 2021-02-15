#include "clerigo.h"
int clerigo::ReturnDamage()const{
	return 5 + rand() % 6; //5 - 10
}

int clerigo::curar(){
	return 6 + rand() % 6; //6 - 11
}
int clerigo::ressucitar(){
	//isso deve implementado melhor, em fase de teste.
	if (hp < 0)	return 10+rand()%2;
	return 0;//10 - 11
}

int clerigo::ReturnHealAmount()const{
	return 6 + rand() % 7;//6- 12
}