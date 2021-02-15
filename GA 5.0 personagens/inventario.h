#pragma once
#include "item.h"

using namespace std;

class inventario
{
public:
	inventario();
	~inventario();

	void setInventarioCabeca(item);
	void setInventarioMaoDir(item);
	void setInventarioMaoEsq(item);
	void setInventarioCinto(item);
	void setInventarioPernas(item);
	void setInventarioPes(item);

	item getInventarioCabeca();
	item getInventarioMaoDir();
	item getInventarioMaoEsq();
	item getInventarioCinto();
	item getInventarioPernas();
	item getInventarioPes();

	void setTipoItem(int);
	int getTipoItem();
protected:
	int tipoItem; //0-cabeca 1-maodir 2-maoesq 3-cinto 4-pernas 5-pes
	item inventarioCabeca;
	item inventarioMaoDir;
	item inventarioMaoEsq;
	item inventarioCinto;
	item inventarioPernas;
	item inventarioPes;

};