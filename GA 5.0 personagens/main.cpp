#include "jogo.h"
#include <iostream>
#include <string>
//a ideia agora � fazer a mesma coisa com o personagens
//implemente os atributo dos personagens e chame-os por arquivo.
//caso n�o d� certo implemente direto da memoria, caso n�o seja posssivel alterar os valores
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
	heran�a e polimofismo
	c++
	organiza��o modular em diversos arquivos
	som e musica
	arquivos para armazenar personagem e item
	evolu��o
	loja
	tela para equipar personagem

	***O grande detalhe do projeto agora � saber
	se � melhor unir as classes jogo e gerenciador
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