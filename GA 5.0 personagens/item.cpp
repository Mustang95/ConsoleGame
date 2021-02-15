#include "item.h"
item::item(){}
item::~item(){}
string item::getNomecabeca(){
	return this->nomeCabeca;
}
int item::getBonusCabeca(){
	return this->bonusCabeca;
}
string item::getNomeMaoDir(){
	return this->nomeMaoDir;
}
int item::getBonusMaoDir(){
	return this->bonusMaoDir;
}
string item::getNomeMaoEsq(){
	return this->nomeMaoEsq;
}
int item::getBonusMaoEsq(){
	return this->bonusMaoEsq;
}
string item::getNomeCinto(){
	return this->nomeCinto;
}
int item::getBonusCinto(){
	return this->bonusCinto;
}
string item::getNomePernas(){
	return this->nomePernas;
}
int item::getBonusPernas(){
	return this->bonusPernas;
}
string item::getNomePes(){
	return this->nomePes;
}
int item::getBonusPes(){
	return this->bonusPes;
}

void item::setNomeCabeca(string n){
	this->nomeCabeca = n;
}
void item::setBonusCabeca(int extra){
	this->bonusCabeca = extra;
}
void item::setNomeMaoDir(string n){
	nomeMaoDir = n;
}
void item::setBonusMaoDir(int extra){
	bonusMaoDir = extra;
}
void item::setNomeMaoEsq(string n){
	nomeMaoEsq = n;
}
void item::setBonusMaoEsq(int extra){
	bonusMaoEsq = extra;
}
void item::setNomeCinto(string n){
	nomeCinto = n;
}
void item::setBonusCinto(int extra){
	bonusCinto = extra;
}
void item::setNomePernas(string n){
	nomePernas = n;
}
void item::setBonusPernas(int extra){
	bonusPernas = extra;
}
void item::setNomePes(string n){
	nomePes = n;
}
void item::setBonusPes(int extra){
	bonusPes = extra;
}