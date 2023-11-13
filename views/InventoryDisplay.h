#pragma once
#include "..\abstractions\inventory\InventoryAbstract.h"
#include "..\abstractions\views\InventoryDisplayAbstract.h"
#include "..\abstractions\inventory\BookAbstract.h"
#include "..\abstractions\inventory\BookObserver.h"

class InventoryDisplay :public InventoryDisplayAbstract, public Observer
{
public:
	void printInventory(InventoryAbstract* b) override
	{
		std::map<int, BookAbstract*> newMap = b->getBookMap();
		for (auto i = newMap.begin(); i != newMap.end(); ++i)
			std::cout << "\n\n" << i->first << ": " << b->getBookCount()[i->first] << " " << i->second->getName() << " " << i->second->getAuthor() << " " << i->second->getGenre()->getGenreId() << " " << i->second->getPrice() << "\n";
	}
	void update() override {
		std::cout << "\nInventory has been updated. Refreshing display...\n";
	}
};
