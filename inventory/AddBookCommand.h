#pragma once
#include "..\abstractions\inventory\BookAbstract.h"
#include "..\abstractions\inventory\InventoryAbstract.h"

class Command {
public:
	virtual void execute() = 0;
};

class AddBookCommand : public Command {
private:
	InventoryAbstract* inventory;
	BookAbstract* book;

public:
	AddBookCommand(InventoryAbstract* inv, BookAbstract* b) : inventory(inv), book(b) {}

	void execute() override {
		inventory->addBook(book);
	}
};