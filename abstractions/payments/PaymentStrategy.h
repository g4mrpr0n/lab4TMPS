#pragma once
class PaymentStrategy {
public:
	virtual float calculateTotal(float originalTotal) = 0;
};