#pragma once
#include "..\inventory\InventoryAbstract.h"
#include "..\inventory\BookAbstract.h"
class CartAbstract
{
public:
	CartAbstract() {};
	virtual void addBookCart(InventoryAbstract* i, int id) = 0;
	virtual float calculateTotal() = 0;
	virtual std::map<int, BookAbstract*> getShoppingCartMap() = 0;
	virtual void emptyShoppingCart() = 0;
};
