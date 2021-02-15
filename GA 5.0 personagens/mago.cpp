#include "mago.h"

int mago::canhaoM(){
	if (mp > 4)	return 10 + rand() % 3;
	return 0;//10 - 12
}
int mago::BolaDFogo(){
	if (mp > 6)	return 12 + rand() % 4;//12 - 15
	return 0;
}
int mago::EscudoM(){
	if (mp > 5) return 5;
	return 0;
}
int mago::relampago(){
	if (mp > 7)	return 13 + rand() % 5; //13 - 17
	return 0;
}
int mago::ReturnDamage()const{
	return 5 + rand() % 3;//5-7
}
int mago::ReturnHealAmount()const{
	return 6 + rand() % 7;//6- 12
}