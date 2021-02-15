#include "guerreiro.h"

int guerreiro::superdef(){
	return 5;
}
int guerreiro::superatq(){
	return 10 +rand()%12; //10 -21
}
int guerreiro::ReturnDamage()const{
	return 4 + rand() % 5;//4 - 8
}
int guerreiro::ReturnHealAmount()const{
	return 6 + rand() % 7;//6-12
}