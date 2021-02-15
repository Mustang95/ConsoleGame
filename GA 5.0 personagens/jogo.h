#pragma once
#include "guerreiro.h"
#include "mago.h"
#include "ladino.h"
#include "clerigo.h"
#include "lobo.h"
#include "vampiro.h"
#include "demonio.h"

#include "item.h"
#include "inventario.h"


#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <locale>
#include <stdio.h>


using namespace std;

class jogo
{
public:
	jogo();
	~jogo();
	void MainMenu();

	int fimEscolha;
	void iniciaJogador();
	int topoInventario;
	void buscaItensInventario();
	void carregaItensCabeca(int i, ifstream *arq);
	void carregaItensMaoDir(int i, ifstream *arq);
	void carregaItensMaoEsq(int i, ifstream *arq);
	void carregaItensCinto(int i, ifstream *arq);
	void carregaItensPernas(int i, ifstream *arq);
	void carregaItensPes(int i, ifstream *arq);

	//void setPlayerClasses();

	void mostraItemCabeca(item head, int indice);
	void mostraItemMaoDir(item handR, int indice);
	void mostraItemMaoEsq(item handL, int indice);
	void mostraItemCinto(item belt, int indice);
	void mostraItemPernas(item legs, int indice);
	void mostraItemPes(item foot, int indice);

protected:




	int inicializaGrupo();
	void setPlayerClasses(int);
	void setPlayerData();


	void setMap();
	void setMap2();
	void setMap3();

	void setEnemy();
	//void setEnemyLobo();
	//void setEnemyVampiro();
	//void setEnemyDemonio();
	void StartGame();
	bool jogarNovamente();
	void MenuInGame();
	void Battle();

	void imprimeStatus(jogador ,inimigo );
	void imprimeInterface(jogador ,inimigo );

	jogador *_Player;
	inimigo *_Enemy;

	inventario inventarioJogador[19];
	item cabeca[3];
	item maoDir[3];
	item maoEsq[3];
	item cinto[3];
	item pernas[3];
	item pes[3];
};