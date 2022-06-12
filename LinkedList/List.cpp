#include "List.h"


List::List() : head(nullptr), tail(nullptr)
{

};

List::~List()
{
	clear();
}

bool List::isEmpty() const
{
	return head == nullptr;
}

void List::push(Resistor resistor)
{
	if (isEmpty())
	{
		head = new Node;
		head->data = resistor;
		head->prev = nullptr;
		head->next = nullptr;
		tail = head;
	}
	else if(head->prev == nullptr && head->next == nullptr)
	{
		Node* current = new Node;
		current->data = resistor;
		current->prev = head;
		current->next = head;
		tail = current;
		head->prev = tail;
		head->next = tail;
	}
	else 
	{

		Node* current = head;
		while (current->data.type < resistor.type || (current->data.type == resistor.type && current->data.denomination < resistor.denomination))
		{
			if (current == tail)
				break;
			current = current->next;
		}

		Node* temp = new Node;
		if (current->prev != nullptr)
			current->prev->next = temp;


		temp->data = resistor;
		temp->prev = current->prev;
		temp->next = current;

		current->prev = temp;
		
	}

}

void List::out(double accuracy) const
{
	if (head == nullptr)
	{
		return;
	}

	Node* current = head;
	while (current != tail)
	{
		if (current->data.accuracy > accuracy)
		{
			std::cout << "<<---------->>" << std::endl;
			std::cout << current->data << std::endl;
		}
		current = current->next;

	}
	
	if (current->data.accuracy > accuracy)
	{
		std::cout << "<<---------->>" << std::endl;
		std::cout << current->data;
	}
}

void List::clear()
{
	if (isEmpty())
	{
		return;
	}
	head = nullptr;

	Node* current = head;
	while (current != nullptr)
	{
		Node* tmp = current;
		current = current->next;
		delete tmp;
	}
	head = nullptr;
	tail = nullptr;
}

void List::pop_back()
{
	if (isEmpty())
		return;

	Node* tmp = tail;
	tail = tail->prev;
	tail->next = tmp->next;
	tmp->next->prev = tail;
	delete(tmp);

}

void List::pop_front()
{
	if (isEmpty())
		return;
	
	Node* tmp = head;
	head = head->next;
	head->prev = tmp->prev;
	tmp->prev->next = head;
	delete(tmp);

}