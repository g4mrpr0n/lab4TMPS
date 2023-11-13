#pragma once
#include "..\inventory\InventoryAbstract.h"

class InventoryDisplayAbstract
{
public:
	virtual void printInventory(InventoryAbstract* b) = 0;
};
