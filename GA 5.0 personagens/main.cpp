#include "jogo.h"
#include <iostream>
#include <string>
//a ideia agora é fazer a mesma coisa com o personagens
//implemente os atributo dos personagens e chame-os por arquivo.
//caso não dê certo implemente direto da memoria, caso não seja posssivel alterar os valores
//inventario(x) personagens(x) batalha() arena()
/*
	tela principal
	tela creditos
	continuar(load)
	tela de jogo
	tela do mapa
	tela de time
	////////////////////////////////////
	classes:	atributos e metodos
	herança e polimofismo
	c++
	organização modular em diversos arquivos
	som e musica
	arquivos para armazenar personagem e item
	evolução
	loja
	tela para equipar personagem

	***O grande detalhe do projeto agora é saber
	se é melhor unir as classes jogo e gerenciador
	pq elas podem ter comflitos
*/

using namespace std;

int main()
{
	jogo game;
	game.MainMenu();
	system("pause");
	return 0;
}