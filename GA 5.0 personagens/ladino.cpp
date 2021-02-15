#include "ladino.h"
int ladino::ReturnDamage()const{
	return 7 + rand() % 7; //7 - 13
}
int ladino::ReturnHealAmount()const{
	return 6 + rand() % 7;//6 - 12
}
int ladino::apunhalar(){
	if ( mp > 5)return 10 + rand() % 10;
	return 0;//10 - 19
}
int ladino::floreio(){
	if (mp > 3)	return 7 + rand() % 10;
	return 0;
}
int ladino::esquivar(){
	if (mp > 5)	return +10;
	return 0;
}