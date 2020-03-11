#include "List.h"

List::List() : size(0), first(nullptr) {}

List::~List() 
{

}

List::Node* List::find(const size_t index)
{
	List::Node* it = first;

	for (size_t i = 0; i < index; i++)
	{
		it = it->next;
	}
	return it;
}

void List::push(const Point& point, const size_t index)
{
	List::Node* node = new List::Node(point);
	if (index == 0) 
	{
		node->next = first;
		first = node;
	}
	else
	{
		List::Node* last = find(index - 1);
		node->next = last->next;
		last->next = node;
	}
	size++;
}

void List::pop(const size_t index)
{
	if (index == 0) 
	{
		List::Node* temp = first;
		first = first->next;
		delete temp;
	}
	else
	{
		List::Node* temp = find(index - 1);
		List::Node* temp2 = temp->next;
		temp->next = temp->next->next;
		delete temp2;
	}
	size--;
}

Error List::push_back(const Point& point)
{
	push(point, size);
	return Error::SUCCES;
}

int List::get_size()
{
	return size;
}