#pragma once
#include "Resistor.h"

struct Node
{
	Node* prev = nullptr;
	Resistor data;
	Node* next = nullptr;
};

class List
{
private:
	Node* head;
	Node* tail;

public:
	List();
	~List();

	bool isEmpty() const;
	void push(Resistor resistor);
	void out(double accuracy) const;
	void clear();
	void pop_front();
	void pop_back();

};

