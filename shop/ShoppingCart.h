#pragma once
#include <map>
#include <iostream>
#include "..\abstractions\payments\CartAbstract.h"

class ShoppingCart : public CartAbstract
{
private:
	std::map<int, BookAbstract*>shoppingCartMap;
public:
	ShoppingCart() = default;
	void addBookCart(InventoryAbstract* i, int id) override
	{
		auto it = shoppingCartMap.find(id);
		if (it == shoppingCartMap.end())
		{
			auto newMap = i->getBookMap();
			auto itr = newMap.find(id);
			if (itr == newMap.end())
			{
				std::cout << "\nThat book doesn't exist in our inventory.\n";
			}
			else if (i->getBookCount()[id] > 0)
			{
				shoppingCartMap.insert(std::pair<int, BookAbstract*>(id, i->findBook(id)));
				std::cout << "\nBook added successfully to cart.\n";
			}
			else if (i->getBookCount()[id] == 0) {
				std::cout << "\nThat book is sold out.\n";
			}
		}
		else {
			std::cout << "\nItem was already in your shopping cart.\n";
		}
	}
	float calculateTotal() override
	{
		float sum = 0;
		for (auto i = shoppingCartMap.begin(); i != shoppingCartMap.end(); ++i)
		{
			sum += i->second->getPrice();
		}
		return sum;
	}
	std::map<int, BookAbstract*> getShoppingCartMap() override { return shoppingCartMap; }
	void emptyShoppingCart() override
	{
		shoppingCartMap.clear();
	}
};
