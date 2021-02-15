#pragma once
#include <iostream>
#include <string>
using namespace std;
class item
{
public:
	item();
	~item();
	//cabeca
	void setNomeCabeca(string n);
	void setBonusCabeca(int extra);
	int getBonusCabeca();
	string getNomecabeca();

	//mao esquerda
	void setNomeMaoEsq(string n);
	void setBonusMaoEsq(int extra);
	int getBonusMaoEsq();
	string getNomeMaoEsq();

	//mao direita
	void setNomeMaoDir(string n);
	void setBonusMaoDir(int extra);
	int getBonusMaoDir();
	string getNomeMaoDir();

	//cinto
	void setNomeCinto(string n);
	void setBonusCinto(int extra);
	int getBonusCinto();
	string getNomeCinto();

	//pernas
	void setNomePernas(string n);
	void setBonusPernas(int extra);
	int getBonusPernas();
	string getNomePernas();

	//pes
	void setNomePes(string n);
	void setBonusPes(int extra);
	int getBonusPes();
	string getNomePes();
protected:
	string nomeCabeca;
	string nomeMaoDir;
	string nomeMaoEsq;
	string nomeCinto;
	string nomePernas;
	string nomePes;
	int bonusCabeca;
	int bonusMaoDir;
	int bonusMaoEsq;
	int bonusCinto;
	int bonusPernas;
	int bonusPes;
};

