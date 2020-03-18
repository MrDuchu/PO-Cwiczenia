#pragma once
#include "Point.h"
#include <iostream>

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

	Node* find(const std::size_t index);
	void pop(const std::size_t index);
	void push(const Point& point, const std::size_t index);


public:
	List();
	~List();

	Error pop_back();
	Error push_back(const Point& point);
	Error find(Point& result, const std::size_t index);
	Error insert(const Point& newPoint, const std::size_t index);

	std::size_t get_size();
};