#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <conio.h>
#include "genres/FictionGenre.h"
#include "shop/ShoppingCart.h"
#include "shop/MakePurchase.h"
#include "views/ViewShoppingCart.h"
#include "inventory/BookInventory.h"
#include "views/InventoryDisplay.h"
#include "shop/PaymentStrategyConcrete.h"
#include "inventory/AddBookCommand.h"

int main()
{
	char step1;
	int choice;

	BookInventory Inventory;
	InventoryAbstract* inv;
	inv = &Inventory;

	InventoryDisplay display;
	Inventory.addObserver(&display);

	BookGenreAbstract* fs;
	FictionGenre f("Fiction is certainly not Non-Fiction. It is very non-serious.");
	fs = &f;

	CartAbstract* c;
	ShoppingCart s;
	c = &s;

	Command* addCommand = new AddBookCommand(inv, new Book("New Book", "New Author", 2023, fs, 75));
	addCommand->execute();

	BookAbstract* b1 = new Book("Le big meowmeow", "Leon Jenkins", 1999, fs, 50);
	BookAbstract* b2 = new Book("The bright tomorrow", "Anan Poopy", 2020, fs, 100);
	BookAbstract* b3 = new Book("Hello world!", "Alex Mamia", 2009, fs, 60);
	BookAbstract* b4 = new Book("Programmer jokes", "Tom Dandy", 1967, fs, 80);
	BookAbstract* b5 = new Book("Le big meowmeow", "Leon Jenkins", 1999, fs, 50);

	BookAbstract* b6 = new Book("the book!", "me", 2015, fs, 120);
	BookAbstract* b7 = new Book("literally meow", "stinkey", 2022, fs, 150);

	inv->addBook(b1);
	inv->addBook(b2);
	inv->addBook(b3);
	inv->addBook(b4);
	inv->addBook(b5);
	inv->addBook(b6);
	inv->addBook(b7);

	std::string mainMenuClient = "Welcome to Bookstore Management system!\nChoose the option next to the action you want to take.\n\nInventory:\n1. Find Books\n2. Show all books\n\nGenre:\n3. Show Fiction description\n\nShop:\n4. Add book to shopping cart\n5. View shopping cart\n6. Proceed with purchase\n\n";
	std::string menuExtra = "\n(ADMIN ONLY)\n7. Add new Book to Inventory\n8. Change description for Fiction\n\n";
	std::cout << "Welcome to Bookstore Management system!\nPress 'c' if you're a client and 'a' if you're an admin.\n";
	std::cin >> step1;
	while (true)
	{
		system("cls");
		if (step1 == 'c')
		{
			std::cout << mainMenuClient;
			CustomerPaymentStrategy customerStrategy;
			c->setPaymentStrategy(&customerStrategy);
		}
		else if (step1 == 'a')
		{
			std::cout << mainMenuClient + menuExtra;
			AdminPaymentStrategy adminStrategy;
			c->setPaymentStrategy(&adminStrategy);
		}
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			unsigned int bookid;
			std::cout << "Enter book ID:\n";
			std::cin >> bookid;
			BookAbstract* b = inv->findBook(bookid);
			if (b->getPrice() > 0) {
				std::cout << "Found the book:\n" << b->getName() << " " << b->getAuthor() << " " << b->getYear() << " " << b->getGenre()->getGenreId() << " " << b->getPrice() << "\n";
			}
			else {
				std::cout << "\nBook doesn't exist in our inventory.\n";
			}
			_getch();
			break;
		}
		case 2:
		{
			display.printInventory(inv);
			_getch();
			break;
		}
		case 3:
		{	fs->printDescription();
		_getch();
		break;
		}
		case 4:
		{	unsigned int bookid;
		std::cout << "Enter book ID:\n";
		std::cin >> bookid;
		c->addBookCart(inv, bookid);
		_getch();
		break;
		}
		case 5:
		{	ViewShoppingCart v;
		ViewShoppingCartAbstract* view;
		view = &v;

		view->printShoppingCart(c);

		_getch();
		break;
		}
		case 6:
		{	std::cout << "Your total is: ";

		if (step1 == 'c')
		{
			std::cout << c->calculateTotalRate(c->calculateTotal()) << " since you're a customer.";
		}
		else { std::cout << c->calculateTotalRate(c->calculateTotal()) << " since you're an admin."; }
		MakePurchase m;
		MakePurchaseAbstract* makepurchase;
		makepurchase = &m;
		makepurchase->purchase(c, inv);
		_getch();
		break;
		}
		case 7:
		{	if (step1 == 'c') { break; }
		std::cout << "Input the name, author, year and price of the book:\n";
		std::string name, author;
		unsigned int year, price;
		std::cin.ignore();
		std::getline(std::cin, name);
		std::getline(std::cin, author);
		std::cin >> year >> price;
		BookAbstract* b = new Book(name, author, year, fs, price);
		Inventory.addBook(b);
		Inventory.notifyObservers();
		_getch();
		break;
		}
		case 8:
		{	if (step1 == 'c') { break; }
		std::cout << "Enter the new description for Fiction\n";
		std::string description;
		std::cin.ignore();
		std::getline(std::cin, description);
		fs->changeDescription(description);
		_getch();
		break;
		}
		}
	}
}