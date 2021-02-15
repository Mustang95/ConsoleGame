#include "inventario.h"
inventario::inventario(){}
inventario::~inventario(){}

item inventario::getInventarioCabeca(){
	return this->inventarioCabeca;
}
item inventario::getInventarioMaoDir(){
	return this->inventarioMaoDir;
}
item inventario::getInventarioMaoEsq(){
	return this->inventarioMaoEsq;
}
item inventario::getInventarioCinto(){
	return this->inventarioCinto;
}
item inventario::getInventarioPernas(){
	return this->inventarioPernas;
}
item inventario::getInventarioPes(){
	return this->inventarioPes;
}
void inventario::setInventarioCabeca(item cabeca){
	inventarioCabeca = cabeca;
}
void inventario::setInventarioMaoDir(item maodir){
	inventarioMaoDir = maodir;
}
void inventario::setInventarioMaoEsq(item maoesq){
	inventarioMaoEsq = maoesq;
}
void inventario::setInventarioCinto(item cinto){
	inventarioCinto = cinto;
}
void inventario::setInventarioPernas(item pernas){
	inventarioPernas = pernas;
}
void inventario::setInventarioPes(item pes){
	inventarioPes = pes;
}

int inventario::getTipoItem(){
	return this->tipoItem;
}
void inventario::setTipoItem(int item){
	tipoItem = item;
}