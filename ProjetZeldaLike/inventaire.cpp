#include "inventaire.h"

void Inventaire::addItem(ItemEntity* item)
{
	inv.push_back(item);
}

vector<ItemEntity*> Inventaire::getInv()
{
	return inv;
}