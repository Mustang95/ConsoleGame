#include "jogador.h"


void jogador::saveGame(){
	//string ttnome = jogador::getNome();
	//const int l = ttnome.length();
	//char tnome[3];
	//for (int n = 0; n < ttnome.length(); n++){
//		tnome[n] = ttnome[n];
//	}
	int tthp = jogador::getHp();
	int ttmp = jogador::getMp();
	int ttdef = jogador::getDef();
	int tthitrate = jogador::getHitRate();
	int ttspeed = jogador::getSpeed();
	int ttevasion = jogador::getEvasion();
	int ttluck = jogador::getLuck();
	int ttarrows = jogador::arrows;
	int ttbombs = jogador::bombs;
	int ttpotions = jogador::potions;

	ofstream salvar;
	salvar.open("salvar.dat", ios::binary);
	if (!salvar){
		cout << "arquivo nao pode ser aberto" << endl;
	}
//	salvar.write(reinterpret_cast<const char*> (&tnome), sizeof(tnome));
	salvar.write(reinterpret_cast<const char*> (&tthp), sizeof(int));
	salvar.write(reinterpret_cast<const char*> (&ttmp), sizeof(int));
	salvar.write(reinterpret_cast<const char*> (&ttdef), sizeof(int));
	salvar.write(reinterpret_cast<const char*> (&tthitrate), sizeof(int));
	salvar.write(reinterpret_cast<const char*> (&ttspeed), sizeof(int));
	salvar.write(reinterpret_cast<const char*> (&ttevasion), sizeof(int));
	salvar.write(reinterpret_cast<const char*> (&ttluck), sizeof(int));
	salvar.write(reinterpret_cast<const char*> (&ttarrows), sizeof(int));
	salvar.write(reinterpret_cast<const char*> (&ttbombs), sizeof(int));
	salvar.write(reinterpret_cast<const char*> (&ttpotions), sizeof(int));
	salvar.close();
	cout << "jogo salvo" << endl;

}

void jogador::loadGame(){
	int tthp,ttmp, ttdef,ttspeed,ttevasion, tthitrate, ttluck, ttarrow, ttbombs,
		ttpotions;
	char tnome[3];
	string ttnome = "   ";

	ifstream carregar;
	carregar.open("salvar.dat", ios::binary);
	if (!carregar){
		cout << "arquivo nao pode ser aberto" << endl;
	}
//	carregar.read(reinterpret_cast<char*> (&ttnome), sizeof(ttnome));
	carregar.read(reinterpret_cast<char*> (&tthp), sizeof(int));
	carregar.read(reinterpret_cast<char*> (&ttmp), sizeof(int));
	carregar.read(reinterpret_cast<char*> (&ttdef), sizeof(int));
	carregar.read(reinterpret_cast<char*> (&tthitrate), sizeof(int));
	carregar.read(reinterpret_cast<char*> (&ttspeed), sizeof(int));
	carregar.read(reinterpret_cast<char*> (&ttevasion), sizeof(int));
	carregar.read(reinterpret_cast<char*> (&ttluck), sizeof(int));
	carregar.read(reinterpret_cast<char*> (&ttarrow), sizeof(int));
	carregar.read(reinterpret_cast<char*> (&ttbombs), sizeof(int));
	carregar.read(reinterpret_cast<char*> (&ttpotions), sizeof(int));
	carregar.close();

//	jogador::setNome(ttnome);
//	for (int n = 0; n < 3; n++){
//		ttnome[n] = tnome[n];
//	}
	jogador::setHp(tthp);
	jogador::setMp(ttmp);
	jogador::setDef(ttdef);
	jogador::setSpeed(ttspeed);
	jogador::setEvasion(ttevasion);
	jogador::setHitRate(tthitrate);
	jogador::setLuck(ttluck);
	jogador::arrows;
	jogador::bombs;
	jogador::potions;

}
item jogador::getCabeca(){ return this->cabeca; }
item jogador::getMaoDir(){ return this->maoDir; }
item jogador::getMaoEsq(){ return this->maoEsq; }
item jogador::getCinto(){ return this->cinto; }
item jogador::getPernas(){ return this->pernas; }
item jogador::getPes(){ return this->pes; }

void jogador::setCabeca(item head){ this->cabeca = head; }
void jogador::setMaoDir(item handR){ this->maoDir = handR; }
void jogador::setMaoEsq(item handL){ this->maoEsq = handL; }
void jogador::setCinto(item belt){ this->cinto = belt; }
void jogador::setPernas(item legs){ this->pernas = legs; }
void jogador::setPes(item feet){ this->pes = feet; }


void jogador::setPlayerData(){
	ifstream ReadData;
	ReadData.clear();
	ReadData.open("data.txt");

	ReadData >> player_type;
	ReadData >> nome;
	ReadData >> hp;
	ReadData >> mp;
	ReadData >> def;
	ReadData >> hitRate;
	ReadData >> speed;
	ReadData >> evasion;
	ReadData >> luck;
	ReadData >> arrows;
	ReadData >> bombs;
	ReadData >> potions;
	ReadData.close();
}

int jogador::attack(){

	int escolha = 0;
	displayInventory();

	cout << "Faça sua jogada:" << endl
		<< "1) Ataque" << endl
		<< "2) Especial Move" << endl
		<< "3) Arco e flecha" << endl
		<< "4) Curar-se" << endl << endl
		<< "5) Usar Bomba" << endl
		<< "6) Usar Poção" << endl
		<< "7) Defender-se" << endl
		<< "0) FUGIR!" << endl << endl;
	while (true){
		cin >> escolha;
		switch (escolha) {
		case 0:
			return fugir();
		case 1:
			// Player generically attacks.
			return atqGenerico();//GenericAttack();
		case 2:
			// Player takes a risk and attacks.
			return atqGenerico();//RiskAttack();//especial move
		case 3:
			// Player shoots their bow.
			if (arrows > 0)
				return bowAndArrow(); //BowAndArrow();
			break;
		case 4:
			// Player heals, no damage is done to enemy.
			heal();
			return 0;
		case 5:
			// Player throws a bomb.
			// Does not execute if there are no bombs in the inventory.
			if (bombs > 0)
				return UseBomb();
			break;
		case 6:
			// Player drinks a potion.
			// Does not execute if there are no potions in the inventory.
			if (potions > 0) {
				usePotion();
				return 0;
			}
			break;
		case 7:
			//para defender
			//deductDamage(int &damage);
			return 0;
			//}
			break;
		default:
			// Generically attacks by default if player's choice does not equal above cases.
			return atqGenerico(); //GenericAttack();
		}
	}
}

void jogador::addToinventory(vector<int> drops){
	// Adds items to inventory and prints out what the player received.

	// Adds items received to total items.
	arrows += drops.at(0);
	bombs += drops.at(1);
	potions += drops.at(2);
//	whetstones += drops.at(3);
//	coins += drops.at(4);


	// Prints number of items received.
	cout << "Você ganhou: " << endl;
	if (drops[0] > 0)
		cout << "[" << drops.at(0) << "] flechas" << endl;
	if (drops[1] > 0)
		cout << "[" << drops.at(1) << "] bombas" << endl;
	if (drops[2] > 0)
		cout << "[" << drops.at(2) << "] poções" << endl;
	//if (drops[3] > 0)
	//	cout << "[" << drops.at(3) << "] whetstones" << endl;
	//if (drops[4] > 0)
	//	cout << "[" << drops.at(4) << "] coins" << endl;

	cout << endl;
}

int jogador::atqGenerico()const{
	int damage = ReturnDamage();
	cout << " dano causado";
	cout << " pontos de dano " << endl;
	if (damage > 0)
		return damage;
	return 0;
}

int jogador::ReturnDamage()const{
	return 0;
}
int jogador::ReturnHealAmount()const{
	return 0;
}

//printar arena em outra classe, por exemplo, classe jogo.

void jogador::recuperaHP(){
	// Adds health points after player has defeated an enemy.
	if (hp <= 0)
		hp = 100;
	else {
		hp += 30;
		if (hp > 100) hp = 100;
	}
}
void jogador::displayInventory(){
	
	// Simply prints the player's inventory.
	
	cout << "*----------- INVENTARIO COMUM -----------* " << endl;
	cout << "| Flechas: [" << arrows << "]" << endl;
	cout << "| Poções: [" << potions << "]" << endl;
	cout << "| Bombas: [" << bombs << "]" << endl;
	cout << "*----------------------------------------*" << endl << endl;
}

//special move from de personagens
int jogador::bowAndArrow(){
	int damage = returnBowDamage();
	//deductDamage(damage);
	cout << " jogou a flecha e acertou ";
	cout << damage;
	cout << " pontos de dano " << endl;
	return damage;
}

void jogador::usePotion(){
	hp = 100;
	cout << " tomou uma poção de cura ";
	potions--;
}

int jogador::UseBomb(){
	cout << " jogou a bomba, acertou! " << endl;
	cout << " 50 pontos de dano! " << endl;
	bombs--;
	return 50;
}

int jogador::returnBowDamage(){
	if (arrows < 1)
		return 0;
	arrows--;
	return 10 + rand() % 6; // 10 - 15
}

int jogador::fugir(){
	cout << " Você está fugindo " << endl;
	return -1;
}