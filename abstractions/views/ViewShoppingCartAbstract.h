#pragma once
#include "..\payments\CartAbstract.h"

class ViewShoppingCartAbstract
{
public:
	virtual void printShoppingCart(CartAbstract* s) = 0;
};
