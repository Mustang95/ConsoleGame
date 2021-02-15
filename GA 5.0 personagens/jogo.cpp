#include "jogo.h"
#include "loop.h"
using namespace loop;

jogo::jogo(){
	topoInventario = 0;
	fimEscolha = 0;
}
jogo::~jogo(){}

void jogo::MainMenu(){
	setlocale(LC_ALL, "portuguese");
	jogador chamo;
	ifstream *arq = new ifstream;
	arq->open("cabeca.txt");
	carregaItensCabeca(-1, arq);
	arq->close();
	arq->open("mao direita.txt");
	carregaItensMaoDir(-1, arq);
	arq->close();
	arq->open("mao esquerda.txt");
	carregaItensMaoEsq(-1, arq);
	arq->close();
	arq->open("cinto.txt");
	carregaItensCinto(-1, arq);
	arq->close();
	arq->open("pernas.txt");
	carregaItensPernas(-1, arq);
	arq->close();
	arq->open("pes.txt");
	carregaItensPes(-1, arq);
	arq->close();

	int op = 0;
	do
	{
		system("cls");
		string linha;
		ifstream is;

		is.open("logo.txt");
		if (!is.is_open())
		{
			cout << "Não foi possível abrir arquivo!Programa sera terminado!" << "\n";
		}
		while (getline(is, linha))
		{
			cout << linha << '\n';
		}
		is.close();


		cout << "[1]NOVOJOGO\t[2]CARREGAR JOGO\t[3]CREDITOS\t[4]SAIR\n";
		cin >> op;
		switch (op)
		{
		case 1:
			//choose your team and choose your weapons
			//iniciaJogo(); Select character();
			//select itens
			StartGame();
			//select characters
			//select items
			//select Map();
			system("pause");
			break;
		case 2:
			//gameload, continue
			//chamo.saveGame();
			chamo.loadGame();
				system("pause");
			break;
		case 3:
			cout << "\n*-----------------------Creditos para Luiz Henrique-----------------------*\n" << endl;
			system("pause");
			break;
		case 4:/*SAIR*/
			break;
		default:
			cout << "OPCAO INVALIDA" << endl;
			system("pause");
		}
	} while (op != 4);
}




void jogo::setPlayerData(){
	ifstream ReadData;
	ReadData.open("data.txt");
	//
	if (!ReadData){
		ReadData.close();
		ofstream WriteData;
		WriteData.open("data.txt");
		WriteData << inicializaGrupo() << endl <<
			"AAA" << endl <<
			100 << endl <<		//hp
			0 << endl <<		//mp
			2 << endl <<		//def
			2 << endl <<		//hitrate
			2 << endl <<		//speed
			2 << endl <<		//evasion
			2 << endl <<		//luck
			2 << endl <<		//arrows
			2 << endl <<		//bombs
			2;					//potions
		WriteData.close();
	}
	else{
		int player_class;
		ReadData >> player_class;
		setPlayerClasses(player_class);
		ReadData.close();
	}
}

void jogo::setMap(){
	//escolhe osmapas disopniveis
	//outras funções para mostrar ao jogador
	//as proximos faases, de forma mais simples
	//usar leitura de arquivos para agregar valor
	//ao projeto.
	string linha;
	ifstream is;
	
	is.open("mapa1.txt");
	if (!is.is_open())
	{
		cout << "Não foi possível abrir arquivo!Programa sera terminado!" << "\n";
	}
	while (getline(is, linha))
	{
		cout << linha << '\n';
	}
	is.close();
}

void jogo::setMap2(){
	string linha;
	ifstream is;

	is.open("mapa2.txt");
	if (!is.is_open())
	{
		cout << "Não foi possível abrir arquivo!Programa sera terminado!" << "\n";
	}
	while (getline(is, linha))
	{
		cout << linha << '\n';
	}
	is.close();
}

void jogo::setMap3(){
	string linha;
	ifstream is;

	is.open("mapa3.txt");
	if (!is.is_open())
	{
		cout << "Não foi possível abrir arquivo!Programa sera terminado!" << "\n";
	}
	while (getline(is, linha))
	{
		cout << linha << '\n';
	}
	is.close();
}

int jogo::inicializaGrupo(){
	int player_class;
	cout << endl
		<< "Ecolha com quem você quer jogar." << endl
		<< "1) Guerreiro " << endl
		<< "2) Mago " << endl
		<< "3) Ladino " << endl
		<< "4) Clerigo " << endl
		<< endl << endl
		<< "> ";
	cin >> player_class;
	//setPlayerClasses(player_class);
	//return player_class[2];
	setPlayerClasses(player_class);
	return player_class;
}

void jogo::setPlayerClasses(int player_class){
	switch (player_class) {
	case 1:
		// Player's class is a warrior.
		_Player = new guerreiro;
		break;
	case 2:
		// Player's class is a rogue.
		_Player = new mago;
		break;
	case 3:
		// Player's class is a healer.
		_Player = new ladino;
		break;
	case 4:
		// Player's class is a debugger.
		// Used to easily defeat enemies. Only for development purposes.
		cout << "bloqueado!!!";
		//_Player = new clerigo;
		break;
	default:
		// If input does not equal any of the cases, the default class is a warrior.
		cout << "escolha os disponíveis";
		//_Player = new ;
		break;
	}
}

void jogo::setEnemy(){
		
	int selection = rand() % 3;
	switch (selection)
	{
	case 0:
		_Enemy = new lobo;
		break;
	case 1:
		_Enemy = new vampiro;
	case 2:
		_Enemy = new demonio;
	default:
		_Enemy = new lobo;
		break;
	}
	
	// Simply prints that the enemy's class was encountered.
	_Enemy->getNome();
	cout << " encountered!" << endl << endl;

}

void jogo::StartGame(){
	srand((unsigned int)time(NULL));
	isPlaying = true;
	system("cls");
	setPlayerData();
	system("cls");
	_Player->setPlayerData();//vazio verificar se sera necessario fazer vector
	//setPlayerClasses();
	//inicializaGrupo();
//	Battle();
	//system("cls");
	iniciaJogador();
	while (isPlaying)
	{
		
		MenuInGame();
		if (!isPlaying)
			break;
		Battle();
	}
	_Player->saveGame();
}

void jogo::Battle(){
	system("cls");
	setEnemy();

	while (isPlaying){
		system("cls");
		//imprime arena
		imprimeInterface(*_Player, *_Enemy);
		//enemy takes damage
		_Enemy->tomaDano(_Player->attack());
		system("pause");
		//
		if (!isPlaying){
			isPlaying = true;
			return;
		}
		if (_Enemy->estaMorto()){
			_Player->addToinventory(_Enemy->getdrops());
			_Player->recuperaHP();

			if (jogarNovamente()) break;
			//retorn stargame, e vai para menuinGame;
			return;
		}
		_Player->tomaDano(_Enemy->ataque());
		system("pause");

		if (_Player->estaMorto()){
			_Player->recuperaHP();
			if (jogarNovamente())break; return;
		}
	}Battle();
}

bool jogo::jogarNovamente(){
	char escolha;
	cout << "Continuar?(y/n)" << endl << endl;
	cin >> escolha;
	if (escolha == 'y' || escolha == 'Y' || escolha == '1') return true;
	//retorna falso pra qualquer coisa que não seja o ques esta no if
	return false;
}

void jogo::MenuInGame(){
	//savegame
	for (int escolha = 0; isPlaying;){
		system("cls");
		cout << "*------------- CheckPoint --------------* " << endl << endl;
		_Player->displayInventory();
		cout << "1) Começar" << endl;
		cout << "2) Salvar jogo" << endl;
		cout << "3) inventario" << endl;
		cout << "4) Quit" << endl << endl;

		cin >> escolha;

		switch (escolha){
		case 1:
			// Returns to StartGame()'s loop, calling Battle().
			//leva para um mapa a escolha do jogador
			//em seguida mostra os inimigos
			system("cls");
			setMap2();
			system("pause");
			return;
		case 2:
			// Goes to the store where the player can buy items.
			/// Currently in working progress.
			_Player->saveGame();
			break;
		case 3:
			// Goes to the gambling arena.
			// _Player is passed in to add items won to the player inventory.
			//faz o personagem re escolher seus itens..
			_Player->displayInventory();
			buscaItensInventario();
			break;
		case 4:
			// Breaks the loop in StartGame(), going back to MainMenu().
			isPlaying = false;
		}
	}
}

void jogo::imprimeStatus(jogador _Player, inimigo _Enemy){
	cout << "\tJOGADOR\t\t\t\t" << "" << "|\t\t\tINIMIGO" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\tNOME:" << _Player.getNome() << "\t\t\t" << "" << "|\t\tNOME:" << _Enemy.getNome() << endl;
	cout << "\tDEFESA:" << _Player.getDef() << "\t\t\t" << "" << "|\t\tDEFESA:" << _Enemy.getDef() << endl;
	cout << "\tESQUIVA:" << _Player.getEvasion() << "\t\t\t" << "" << "|\t\tESQUIVA:" << _Enemy.getEvasion() << endl;
	cout << "\tMP:" << _Player.getMp() << "\t\t\t\t" << "" << "|\t\tMP:" << _Enemy.getMp() << endl;
	cout << "\tACERTO:" << _Player.getHitRate() << "\t\t\t" << "" << "|\t\tACERTO:" << _Enemy.getHitRate() << endl;
	cout << "\tVELOCIDADE:" << _Player.getSpeed() << "\t\t\t" << "" << "|\t\tMOVIMENTO:" << _Enemy.getSpeed() << endl;
	cout << "\tSORTE:" << _Player.getLuck() << "\t\t\t\t" << "" << "|\t\tSORTE:" << _Enemy.getLuck() << endl;
	cout << "\t\t\t\t\t|" << endl;
	cout << "\tVIDA:" << _Player.getHp() << "\t\t\t" << "" << "|\t\tVIDA:" << _Enemy.getHp() << endl;
	cout << endl;
}

void jogo::imprimeInterface(jogador _Player, inimigo _Enemy){
	system("cls");
	imprimeStatus(_Player, _Enemy);
}

void jogo::carregaItensCabeca(int i, ifstream *arq){
	string str_cabeca;
	int extra;
	if (i<3)
	{
		i++;
		*arq >> str_cabeca >> extra;
		cabeca[i].setNomeCabeca(str_cabeca);
		cabeca[i].setBonusCabeca(extra);
		carregaItensCabeca(i, arq);
	}
}

void jogo::carregaItensMaoDir(int i, ifstream *arq){
	string str_maodir;
	int bonusMaodir;
	if (i<3)
	{
		i++;
		*arq >> str_maodir >> bonusMaodir;
		maoDir[i].setNomeMaoDir(str_maodir);
		maoDir[i].setBonusMaoDir(bonusMaodir);
		carregaItensMaoDir(i, arq);
	}
}

void jogo::carregaItensMaoEsq(int i, ifstream *arq){
	string str_maoesq;
	int bonusMaoesq;
	if (i<3)
	{
		i++;
		*arq >> str_maoesq >> bonusMaoesq;
		maoEsq[i].setNomeMaoEsq(str_maoesq);
		maoEsq[i].setBonusMaoEsq(bonusMaoesq);
		carregaItensMaoEsq(i, arq);
	}
}
void jogo::carregaItensCinto(int i, ifstream *arq){
	string str_cinto;
	int bonusCinto;
	if (i<3)
	{
		i++;
		*arq >> str_cinto >> bonusCinto;
		cinto[i].setNomeCinto(str_cinto);
		cinto[i].setBonusCinto(bonusCinto);
		carregaItensCinto(i, arq);
	}
}
void jogo::carregaItensPernas(int i, ifstream *arq){
	string str_pernas;
	int bonusPernas;
	if (i<3)
	{
		i++;
		*arq >> str_pernas >> bonusPernas;
		pernas[i].setNomePernas(str_pernas);
		pernas[i].setBonusPernas(bonusPernas);
		carregaItensPernas(i, arq);
	}
}
void jogo::carregaItensPes(int i, ifstream *arq){
	string str_pes;
	int bonusPes;
	if (i<3)
	{
		i++;
		*arq >> str_pes >> bonusPes;
		pes[i].setNomePes(str_pes);
		pes[i].setBonusPes(bonusPes);
		carregaItensPes(i, arq);
	}
}

void jogo::mostraItemCabeca(item head, int indice){
	cout << indice << ") CAPACETE:" << endl;
	cout << "    Nome.............: " << head.getNomecabeca() << endl;
	cout << "    Bonus ...........: " << head.getBonusCabeca() << endl;
}
void jogo::mostraItemMaoDir(item handR, int indice){
	cout << indice << ") M diretita:" << endl;
	cout << "    Nome.............: " << handR.getNomeMaoDir() << endl;
	cout << "    Bonus ...........: " << handR.getBonusMaoDir() << endl;
}
void jogo::mostraItemMaoEsq(item handL, int indice){
	cout << indice << ") M esquerda:" << endl;
	cout << "    Nome.............: " << handL.getNomeMaoEsq() << endl;
	cout << "    Bonus ...........: " << handL.getBonusMaoEsq() << endl;
}
void jogo::mostraItemCinto(item belt, int indice){
	cout << indice << ") CINTO:" << endl;
	cout << "    Nome.............: " << belt.getNomeCinto() << endl;
	cout << "    Bonus ...........: " << belt.getBonusCinto() << endl;
}
void jogo::mostraItemPernas(item legs, int indice){
	cout << indice << ") PERNAS:" << endl;
	cout << "    Nome.............: " << legs.getNomePernas() << endl;
	cout << "    Bonus ...........: " << legs.getBonusPernas() << endl;
}
void jogo::mostraItemPes(item foot, int indice){
	cout << indice << ") PES:" << endl;
	cout << "    Nome.............: " << foot.getNomePes() << endl;
	cout << "    Bonus ...........: " << foot.getBonusPes() << endl;
}

void jogo::buscaItensInventario(){
	system("cls");
	int seleciona;
	int cont = 0;
	cout << "INVENTARIO" << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		if (inventarioJogador[i].getTipoItem() == 0){
			mostraItemCabeca(inventarioJogador[i].getInventarioCabeca(), i + 1);
			cont++;
		}
		else if (inventarioJogador[i].getTipoItem() == 1){
			mostraItemMaoDir(inventarioJogador[i].getInventarioMaoDir(), i + 1);
			cont++;
		}
		else if (inventarioJogador[i].getTipoItem() == 2){
			mostraItemMaoEsq(inventarioJogador[i].getInventarioMaoEsq(), i + 1);
			cont++;
		}
		else if (inventarioJogador[i].getTipoItem() == 3){
			mostraItemCinto(inventarioJogador[i].getInventarioCinto(), i + 1);
			cont++;
		}
		else if (inventarioJogador[i].getTipoItem() == 4){
			mostraItemPernas(inventarioJogador[i].getInventarioPernas(), i + 1);
			cont++;
		}
		else if (inventarioJogador[i].getTipoItem() == 5){
			mostraItemPes(inventarioJogador[i].getInventarioPes(), i + 1);
			cont++;
		}
	}do{
		cout << "DIGITIE O NUMERO DO ITEM DESEJADO OU (0) PARA SAIR" << endl;
		cin >> seleciona;
	} while (seleciona<0 || seleciona>cont);
	if (seleciona > 0)
	{
		cout << "VOCÊ SELECIONOU O ITEM" << endl << endl;
		seleciona--;
		if (inventarioJogador[seleciona].getTipoItem() == 0)
		{
			mostraItemCabeca(_Player->getCabeca(), seleciona + 1);
			system("pause");
		}
		else if (inventarioJogador[seleciona].getTipoItem() == 1)
		{
			mostraItemMaoDir(_Player->getMaoDir(), seleciona + 1);
			system("pause");
		}
		else if (inventarioJogador[seleciona].getTipoItem() == 2)
		{
			mostraItemMaoEsq(_Player->getMaoEsq(), seleciona + 1);
			system("pause");
		}
		else if (inventarioJogador[seleciona].getTipoItem() == 3)
		{
			mostraItemCinto(_Player->getCinto(), seleciona + 1);
			system("pause");
		}
		else if (inventarioJogador[seleciona].getTipoItem() == 4)
		{
			mostraItemPernas(_Player->getPernas(), seleciona + 1);
			system("pause");
		}
		else if (inventarioJogador[seleciona].getTipoItem() == 5)
		{
			mostraItemPes(_Player->getPes(), seleciona + 1);
			system("pause");
		}
	}
}

void jogo::iniciaJogador(){
	int op;
	int opCabeca, opMaoDir, opMaoEsq, opCinto, opPernas, opPes;
	bool selCabeca = false, selMaoDir = false, selMaoEsq = false, selCinto = false,
		selPernas = false, selPes = false;
	do{
		system("cls");
		if (selCabeca&&selMaoDir&&selMaoEsq&&selCinto&&selPernas&&selPes){
			cout << "[1]SELECIONA CAPACETE\n[2]SELECIONA MÃO DIREITA\n[3]SELECIONA MÃO ESQUERDA\n"
				"[4]SELECIONA CINTO\n[5]SELECIONA PERNEIRAS\n[6]SELECIONA PÉS\n[7]COMEÇA\n[0]VOLTAR\n\n";
		}
		else{
			cout << "[1]SELECIONA CAPACETE\n[2]SELECIONA MÃO DIREITA\n[3]SELECIONA MÃO ESQUERDA\n"
				"[4]SELECIONA CINTO\n[5]SELECIONA PERNEIRAS\n[6]SELECIONA PÉS\n[0]VOLTAR\n\n";
		}
		cout << "DIGITE A OPÇÃO DESEJADA: ";
		cin >> op;
		switch (op)
		{
		case 1:
			do
			{
				system("cls");
				cout << "SELECIONA CAPACETE: " << endl << endl;
				cout << "CODIDO NOME		BONUS\n";
				cout << setfill('-') << setw(7) << right << " " << setw(14) << " " << setw(16) << " " << setw(8) << " " << setw(18) << "\n";

				for (int i = 0; i < 3; i++)//para a quantidade de itens por slot
				{
					cout << setfill(' ') << setw(6) << left << i + 1 << " " << setw(13) << cabeca[i].getNomecabeca() << " " << setw(15) << cabeca[i].getBonusCabeca() << " " << endl;
				}
				cout << "\nDIGITE O CODIGO DO ITEM DESEJADO: ";
				cin >> opCabeca;
			} while (opCabeca < 1 || opCabeca>3);
			inventarioJogador[0].setInventarioCabeca(cabeca[opCabeca - 1]);//item selecionado
			inventarioJogador[0].setTipoItem(0);
			_Player->setCabeca(cabeca[opCabeca - 1]);//equipado no jogador
			selCabeca = true;
			break;
		case 2:
			do
			{
				system("cls");
				cout << "SELECIONA MÃO DIREITA: " << endl << endl;
				cout << "CODIDO NOME		BONUS\n";
				cout << setfill('-') << setw(7) << right << " " << setw(14) << " " << setw(16) << " " << setw(8) << " " << setw(18) << "\n";

				for (int i = 0; i < 3; i++)//para a quantidade de itens por slot
				{
					cout << setfill(' ') << setw(6) << left << i + 1 << " " << setw(13) << maoDir[i].getNomeMaoDir() << " " << setw(15) << maoDir[i].getBonusMaoDir() << " " << endl;
				}
				cout << "\nDIGITE O CODIGO DO ITEM DESEJADO: ";
				cin >> opMaoDir;
			} while (opMaoDir < 1 || opMaoDir>3);
			inventarioJogador[1].setInventarioMaoDir(maoDir[opMaoDir - 1]);//item selecionado
			inventarioJogador[1].setTipoItem(1);
			_Player->setMaoDir(maoDir[opMaoDir - 1]);//equipado no jogador
			selMaoDir = true;
			break;
		case 3:
			do
			{
				system("cls");
				cout << "SELECIONA MÃO ESQUERDA: " << endl << endl;
				cout << "CODIDO NOME		BONUS\n";
				cout << setfill('-') << setw(7) << right << " " << setw(14) << " " << setw(16) << " " << setw(8) << " " << setw(18) << "\n";

				for (int i = 0; i < 3; i++)//para a quantidade de itens por slot
				{
					cout << setfill(' ') << setw(6) << left << i + 1 << " " << setw(13) << maoEsq[i].getNomeMaoEsq() << " " << setw(15) << maoEsq[i].getBonusMaoEsq() << " " << endl;
				}
				cout << "\nDIGITE O CODIGO DO ITEM DESEJADO: ";
				cin >> opMaoEsq;
			} while (opMaoEsq < 1 || opMaoEsq>3);
			inventarioJogador[2].setInventarioMaoEsq(maoEsq[opMaoEsq - 1]);//item selecionado
			inventarioJogador[2].setTipoItem(2);
			_Player->setMaoEsq(maoEsq[opMaoEsq - 1]);//equipado no jogador
			selMaoEsq = true;
			break;
		case 4:
			do
			{
				system("cls");
				cout << "SELECIONA CINTO: " << endl << endl;
				cout << "CODIDO NOME		BONUS\n";
				cout << setfill('-') << setw(7) << right << " " << setw(14) << " " << setw(16) << " " << setw(8) << " " << setw(18) << "\n";

				for (int i = 0; i < 3; i++)//para a quantidade de itens por slot
				{
					cout << setfill(' ') << setw(6) << left << i + 1 << " " << setw(13) << cinto[i].getNomeCinto() << " " << setw(15) << cinto[i].getBonusCinto() << " " << endl;
				}
				cout << "\nDIGITE O CODIGO DO ITEM DESEJADO: ";
				cin >> opCinto;
			} while (opCinto < 1 || opCinto>3);
			inventarioJogador[3].setInventarioCinto(cinto[opCinto - 1]);//item selecionado
			inventarioJogador[3].setTipoItem(3);
			_Player->setCinto(cinto[opCinto - 1]);//equipado no jogador
			selCinto = true;
			break;
		case 5:
			do
			{
				system("cls");
				cout << "SELECIONA PERNEIRAS: " << endl << endl;
				cout << "CODIDO NOME		BONUS\n";
				cout << setfill('-') << setw(7) << right << " " << setw(14) << " " << setw(16) << " " << setw(8) << " " << setw(18) << "\n";

				for (int i = 0; i < 3; i++)//para a quantidade de itens por slot
				{
					cout << setfill(' ') << setw(6) << left << i + 1 << " " << setw(13) << pernas[i].getNomePernas() << " " << setw(15) << pernas[i].getBonusPernas() << " " << endl;
				}
				cout << "\nDIGITE O CODIGO DO ITEM DESEJADO: ";
				cin >> opPernas;
			} while (opPernas < 1 || opPernas>3);
			inventarioJogador[4].setInventarioPernas(pernas[opPernas - 1]);//item selecionado
			inventarioJogador[4].setTipoItem(4);
			_Player->setPernas(pernas[opPernas - 1]);//equipado no jogador
			selPernas = true;
			break;
		case 6:
			do
			{
				system("cls");
				cout << "SELECIONA BOTAS: " << endl << endl;
				cout << "CODIDO NOME		BONUS\n";
				cout << setfill('-') << setw(7) << right << " " << setw(14) << " " << setw(16) << " " << setw(8) << " " << setw(18) << "\n";

				for (int i = 0; i < 3; i++)//para a quantidade de itens por slot
				{
					cout << setfill(' ') << setw(6) << left << i + 1 << " " << setw(13) << pes[i].getNomePes() << " " << setw(15) << pes[i].getBonusPes() << " " << endl;
				}
				cout << "\nDIGITE O CODIGO DO ITEM DESEJADO: ";
				cin >> opPes;
			} while (opPes < 1 || opPes>3);
			inventarioJogador[5].setInventarioPes(pes[opPes - 1]);//item selecionado
			inventarioJogador[5].setTipoItem(5);
			_Player->setPes(pes[opPes - 1]);//equipado no jogador
			selPes = true;
			break;
		case 7: return; break;
		case 8:
			if (selCabeca&&selMaoDir&&selMaoEsq&&selCinto&&selPernas&&selPes){
				op = 0;
				topoInventario = 6;//quantidade de itens nos personagens
			}
			else{
				op = 18;
			}break;
		default:cout << "OPÇÃO INVALIDA" << endl; system("pause");
		}
	} while (op != '0');
}