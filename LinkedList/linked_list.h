#include <functional>
#include <iostream>
#pragma once

struct node
{
	int value;
	std::shared_ptr<node> next = nullptr;
};

class linked_list
{
public:
	linked_list();
	~linked_list();
	void add(int value);
	void for_each(const std::function<void(const std::shared_ptr<node>)>& action);
	const void print();

private:
	std::shared_ptr<node> first = nullptr;
};



