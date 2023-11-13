#pragma once
#include "BookAbstract.h"
#include <map>
#include <iostream>

class InventoryAbstract
{
public:
	virtual void addBook(BookAbstract* book) = 0;
	virtual BookAbstract* findBook(int id) = 0;
	virtual void removeBookCount(int id) = 0;
	virtual std::map<int, BookAbstract*> getBookMap() = 0;
	virtual	int* getBookCount() = 0;
	virtual int getLastIndex() = 0;
};
