#pragma once
#include "..\abstractions\payments\PaymentStrategy.h"

class CustomerPaymentStrategy : public PaymentStrategy {
public:
	float calculateTotal(float originalTotal) override {
		return originalTotal * 1.0;  // No discount for customers
	}
};

class AdminPaymentStrategy : public PaymentStrategy {
public:
	float calculateTotal(float originalTotal) override {
		return originalTotal * 0.5;  // 50% discount for admins
	}
};