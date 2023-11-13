#pragma once
#include <map>
#include "Book.h"
#include "..\abstractions\inventory\InventoryAbstract.h"
#include "..\abstractions\inventory\BookObserver.h"

class BookInventory : public InventoryAbstract, public Subject
{
private:
	std::map<int, BookAbstract*>BookMap; //map individual key to one book
	std::vector<Observer*> observers;
	int BookCount[256]; //keep track of count of each book
	int lastIndex = -1;
public:
	BookInventory() = default;

	void addObserver(Observer* observer) override {
		observers.push_back(observer);
	}

	void notifyObservers() override {
		for (Observer* observer : observers) {
			observer->update();
		}
	}

	void addBook(BookAbstract* book) override
	{
		bool exists = false;
		std::map<int, BookAbstract*>::iterator i;
		for (i = BookMap.begin(); i != BookMap.end(); ++i) //see if the book already exists in the inventory
		{
			if (i->second->getName() == book->getName() && i->second->getAuthor() == book->getAuthor())
			{
				exists = true;
				break;
			}
		}
		if (exists)
		{
			BookCount[i->first]++;
			BookCount[i->first];
		}
		else { //otherwise add new book
			//check last nonzero index
			for (int i = 0; i <= 255; i++)
			{
				if (BookCount[i] > 0)
				{
					if (i == 255)
					{
						lastIndex = -1; // all entries are full
					}
					continue;
				}
				else if (BookCount[i] == 0)
				{
					lastIndex = i;
					break;
				}
			}

			//found last null entry
			if (lastIndex <= 255 && lastIndex != -1)
			{
				BookMap.insert({ lastIndex , book });
				BookCount[lastIndex]++;
			}
		}
	}
	BookAbstract* findBook(int id) override
	{
		std::map<int, BookAbstract*>::iterator it = BookMap.find(id);

		if (it != BookMap.end()) {
			BookAbstract* foundBook = it->second;
			return foundBook;
		}
		else {
			BookAbstract* book = new Book();
			return book;
		}
	}
	void removeBookCount(int id) override
	{
		BookCount[id]--;
	}
	std::map<int, BookAbstract*> getBookMap() override
	{
		return BookMap;
	}
	int* getBookCount() override
	{
		return BookCount;
	}
	int getLastIndex() override
	{
		return lastIndex;
	}
};
