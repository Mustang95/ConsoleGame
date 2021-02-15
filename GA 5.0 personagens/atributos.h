#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//atributos é a entidade que fará o arquetipo dos
//personagens ingame.
class atributos
{
public:
	atributos();
	~atributos();

	/////////////////////////////////
	//atributos dos personagens
	string getNome();
	int getHp();
	int getMp();
	int getDef();
	int getSpeed();
	int getHitRate();
	int getEvasion();
	int getLuck();
	void setNome(string nome);
	void setHp(int hp);
	void setMp(int mp);
	void setDef(int def);
	void setSpeed(int speed);
	void setHitRate(int hitRate);
	void setEvasion(int evasion);
	void setLuck(int luck);
	
	void tomaDano(int);
	bool estaMorto();
	
	/////////////////////////////////////////////////////
protected:
	/////////////////////////////////////////////////////
	//estados e ações
	void heal();
	virtual int atqGenerico()const = 0;
	virtual int ReturnDamage()const = 0;
	virtual int ReturnHealAmount()const = 0;
	/////////////////////////////////////////////////////
	string nome;
	int hp;
	int mp;
	int def;
	int speed;
	int hitRate;
	int evasion;
	int luck;
};

