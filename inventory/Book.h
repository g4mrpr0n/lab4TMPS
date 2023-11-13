#pragma once
#include <string>
#include "..\abstractions\inventory\BookGenreAbstract.h"
#include "..\abstractions\inventory\BookAbstract.h"

class Book : public BookAbstract
{
private:

	BookGenreAbstract* genre;
	std::string name;
	std::string author;
	int year;
	double price;
public:
	Book() = default;
	Book(std::string name, std::string author, int year, BookGenreAbstract* genre, double price) :
		name(name), author(author), year(year), genre(genre), price(price) {}
	BookGenreAbstract* getGenre() override
	{
		return genre;
	}
	std::string getName() override
	{
		return name;
	}
	std::string getAuthor() override
	{
		return author;
	}
	int getYear() override
	{
		return year;
	}
	double getPrice() override
	{
		return price;
	}

	std::string getType() override {
		return "Default";
	};
};
