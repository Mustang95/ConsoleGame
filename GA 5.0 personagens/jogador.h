#pragma once
#include <vector>
#include "atributos.h"
#include "inventario.h"
#include "inimigo.h"
class jogador : public atributos
{
public:
	//jogador();
	//~jogador();
	
	void saveGame();
	void loadGame();
	void setPlayerData();
	void setPlayerData2();
	void setPlayerData3();
	int attack();
	
	//////////////////////////////////////
	void addToinventory(vector<int>);	//
	void displayInventory();			//
	//////////////////////////////////////
	void imprimeInterface(inimigo*);
	void recuperaHP();
	item getCabeca();
	item getMaoDir();
	item getMaoEsq();
	item getCinto();
	item getPernas();
	item getPes();
	void setCabeca(item head);
	void setMaoDir(item handR);
	void setMaoEsq(item handL);
	void setCinto(item belt);
	void setPernas(item legs);
	void setPes(item feet);

private:
	

	int bowAndArrow();//arco e flecha
	int fugir();//flee
	void usePotion();
	int UseBomb();

	int atqGenerico()const;
	int ReturnDamage()const;
	int ReturnHealAmount()const;
	int returnBowDamage();

	int player_type;
	int arrows;
	int potions;
	int bombs;

	item cabeca;
	item maoDir;
	item maoEsq;
	item cinto;
	item pernas;
	item pes;
};

