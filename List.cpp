#include "List.h"

List::List() : size(0), first(nullptr) {}

List::~List() 
{

}

List::Node* List::find(const std::size_t index)
{
	List::Node* it = first;

	for (std::size_t i = 0; i < index; i++)
	{
		it = it->next;
	}
	return it;
}

void List::push(const Point& point, const std::size_t index)
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

void List::pop(const std::size_t index)
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

Error List::pop_back()
{
	if (size == 0) {
		return Error::LIST_EMPTY;
	}
	else
	{
		pop(size);
		return Error::SUCCES;
	}
}

Error List::find(Point& result, const std::size_t index) 
{
	if (size == 0)
	{
		return Error::LIST_EMPTY;
	}
	else if (index > size) 
	{
		return Error::OUT_OF_BOUNDS;
	}
	else
	{
		result = find(index)->point;
		return Error::SUCCES;
	}
}

Error List::insert(const Point& newPoint, const std::size_t index)
{
	if (size == 0)
	{
		return Error::LIST_EMPTY;
	}
	else if (index > size)
	{
		return Error::OUT_OF_BOUNDS;
	}
	else
	{
		push(newPoint,index);
		return Error::SUCCES;
	}
}

std::size_t List::get_size()
{
	return size;
}