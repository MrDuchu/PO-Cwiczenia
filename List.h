#pragma once
#include "Point.h"

enum Error
{
	SUCCES,
	OUT_OF_BOUNDS,
	LIST_EMPTY
};

class List
{
private:
	struct Node {
		Point point;
		Node* next;

		Node(const Point point) : next(nullptr), point(point) {}
	};

	Node* first;
	size_t size;

	Node* find(const size_t index);
	void pop(const size_t index);
	void push(const Point& point, const size_t index);


public:
	List();
	~List();

	Error push_back(const Point& point);

	int get_size();
};