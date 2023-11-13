#pragma once
#include "..\inventory\InventoryAbstract.h"
#include "..\inventory\BookAbstract.h"
#include "PaymentStrategy.h"
class CartAbstract
{
private:
	PaymentStrategy* paymentStrategy;
public:
	CartAbstract() {};
	virtual void addBookCart(InventoryAbstract* i, int id) = 0;
	virtual float calculateTotal() = 0;
	virtual std::map<int, BookAbstract*> getShoppingCartMap() = 0;
	virtual void emptyShoppingCart() = 0;

	void setPaymentStrategy(PaymentStrategy* strategy) {
		paymentStrategy = strategy;
	}

	float calculateTotalRate(float originalTotal) {
		return paymentStrategy->calculateTotal(originalTotal);
	}
};
