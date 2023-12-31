#pragma once
#include <vector>

class Observer {
public:
	virtual void update() = 0;
};

class Subject {
public:
	virtual void addObserver(Observer* observer) = 0;
	virtual void notifyObservers() = 0;
};