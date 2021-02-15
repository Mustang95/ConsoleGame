#include "vampiro.h"

int vampiro::ReturnDamage()const{
	return 5;
}
int vampiro::ReturnHealAmount()const{
	return 10;
}

int vampiro::mordida(){
	return 5;
}
int vampiro::pocaDeSangue(){
	if (hp<15)
	return 10;
	return 0;
}
