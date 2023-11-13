# Topic: *Structural Design Patterns*


## Author: Globa Georgeana

----

## Objectives:
&ensp; &ensp; __1. Study and understand the Behavioral Design Patterns.__

&ensp; &ensp; __2. As a continuation of the previous laboratory work, think about what communication between software entities might be involed in your system.__

&ensp; &ensp; __3. Create a new Project or add some additional functionalities using behavioral design patterns.__

## Theoretical background:
&ensp; &ensp; Behavioral design patterns are a category of design patterns that focus on the interaction and communication between objects and classes. They provide a way to organize the behavior of objects in a way that is both flexible and reusable, while separating the responsibilities of objects from the specific implementation details. Behavioral design patterns address common problems encountered in object behavior, such as how to define interactions between objects, how to control the flow of messages between objects, or how to define algorithms and policies that can be reused across different objects and classes.

&ensp; &ensp; Some examples from this category of design patterns are :

   * Chain of Responsibility
   * Command
   * Interpreter
   * Iterator
   * Mediator
   * Observer
   * Strategy

## Implementation

This project is a Bookstore Management System, implemented in C++.

&ensp; The Observer Pattern is used to implement the relationship between the `BookInventory` (subject) and the `InventoryDisplay` (observer). When the inventory changes (e.g., a new book is added), the observers (like `InventoryDisplay`) are notified and can update their displays accordingly. This ensures that different parts of the system can react to changes in the inventory without being tightly coupled.
```cpp
class Observer {
public:
	virtual void update() = 0;
};

class Subject {
public:
	virtual void addObserver(Observer* observer) = 0;
	virtual void notifyObservers() = 0;
};
```

```cpp
class InventoryDisplay : public Observer {
public:
    void update() override {
        std::cout << "Inventory has been updated. Refreshing display...\n";
    }
};
```


```cpp
class BookInventory : public Subject {
private:
    std::vector<Observer*> observers;
    // ...

public:

	//...

    void addObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void notifyObservers() override {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};
```
==================================================================
&ensp; The Strategy Pattern is employed in the payment system. Different payment strategies are possible (e.g., `CustomerPaymentStrategy` and `AdminPaymentStrategy`). The `CartAbstract` has a reference to a `PaymentStrategy`, allowing it to easily switch and use different payment strategies without modifying the cart or payment processing logic directly.

```cpp
class PaymentStrategy {
public:
    virtual float calculateTotal(float originalTotal) = 0;
};
```

```cpp
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
```

```cpp
class CartAbstract {
private:
    PaymentStrategy* paymentStrategy;

public:
    void setPaymentStrategy(PaymentStrategy* strategy) {
        paymentStrategy = strategy;
    }

    float calculateTotal(float originalTotal) {
        return paymentStrategy->calculateTotal(originalTotal);
    }

    // ... 
};
```

==================================================================

&ensp; Command Pattern is introduced with the `Command` interface and the concrete command class `AddBookCommand`. This lets it encapsulate the "add book" operation as a command. The command can be easily executed, and we can extend the system by adding more commands in the future without modifying existing code. It provides a way to decouple the sender of the request  from the object that processes the request.

```cpp
class Command {
public:
    virtual void execute() = 0;
};
```

```cpp
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
```

## Conclusions / Screenshots / Results
In conclusion the patterns collectively enhance the flexibility of the system. Changes in one part of the system have minimal impact on others, making it easier to adapt to evolving requirements. The modular nature of these patterns supports the addition of new features and functionalities with minimal disruption to existing code. Also, by adhering to these design patterns, the codebase becomes more maintainable. Patterns encapsulate specific responsibilities and promote separation of concerns.