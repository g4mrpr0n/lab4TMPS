#pragma once
#include "BookGenreAbstract.h"
class BookAbstract
{
public:
	BookAbstract() = default;
	virtual BookGenreAbstract* getGenre() = 0;
	virtual std::string getName() = 0;
	virtual std::string getAuthor() = 0;
	virtual int getYear() = 0;
	virtual double getPrice() = 0;
	virtual std::string getType() = 0;
};
