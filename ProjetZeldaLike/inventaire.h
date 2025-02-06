#pragma once
#include "itemEntity.h"

class Inventaire
{
public:
	vector<ItemEntity*> inv;
	void addItem(ItemEntity* item);
	vector<ItemEntity*> getInv();
};