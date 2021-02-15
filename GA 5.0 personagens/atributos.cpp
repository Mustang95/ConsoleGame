#include "atributos.h"
#include "loop.h"
using namespace loop;

atributos::atributos(){}
atributos::~atributos(){}
string atributos::getNome(){ return this->nome; }
int atributos::getHp(){ return this->hp; }
int atributos::getMp(){ return this->mp; }
int atributos::getDef(){ return this->def; }
int atributos::getSpeed(){ return this->speed; }
int atributos::getHitRate(){ return this->hitRate; }
int atributos::getEvasion(){ return this->evasion; }
int atributos::getLuck(){ return this->luck; }

void atributos::setNome(string nome){ this->nome = nome; }
void atributos::setHp(int hp){ this->hp = hp; }
void atributos::setMp(int mp){ this->mp = mp; }
void atributos::setDef(int def){ this->def = def; }
void atributos::setSpeed(int speed){ this->speed = speed; }
void atributos::setHitRate(int hitRate){ this->hitRate = hitRate; }
void atributos::setEvasion(int evasion){ this->evasion = evasion; }
void atributos::setLuck(int luck){ this->luck = luck; }

bool atributos::estaMorto(){
	if (hp <= 0){
		cout << "está morto!" << endl << endl;
		return true;
	}
	return false;
}
///////////////////////////////////////////////////
void atributos::tomaDano(int damage){			///
	//se escolher sair, não toma dano.			///
	if (damage == -1){							///
		isPlaying = false;						///
		return;									///
	}											///
	//dano causado pelo jogador em inimigos		///
	hp -= damage;								///
}												///
///////////////////////////////////////////////////
void atributos::heal(){
	int heal = ReturnHealAmount();
	hp += heal;
	if (hp > 100) hp = 100;

	cout << "ganhou " << heal << " de HP!" << endl;
}


/////////////////////////////////////////////////////////////////
int atributos::atqGenerico()const{
	int damage = ReturnDamage();
	cout << "dano causado";
	cout << "pontos de dano" << endl;
	if (damage > 0)
		return damage;
	return 0;
}
int atributos::ReturnDamage()const{
	//função que devera ser melhor implementada
	return 10;
	return 0;
}

int atributos::ReturnHealAmount()const{
	return 6 + rand() % 7;
}
///////////////////////////////////////////////////////////////