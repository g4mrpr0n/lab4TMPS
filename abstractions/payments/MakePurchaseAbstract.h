#pragma once
#include "CartAbstract.h"
#include "..\inventory\InventoryAbstract.h"


class MakePurchaseAbstract
{
public:
	virtual void purchase(CartAbstract* s, InventoryAbstract* b) = 0;
};

