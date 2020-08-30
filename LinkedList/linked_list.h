#include <functional>
#include <iostream>
#pragma once



struct node
{
	int value;
	std::shared_ptr<node> next = nullptr;

	~node() {
	}
};

class linked_list
{
public:
	linked_list();
	~linked_list();
	void add(const int value);
	void for_each(const std::function<void(const std::shared_ptr<node>)>& action) const;
	void insert_after(const int value, const int after);
	std::shared_ptr<node> insert_node(std::shared_ptr<node>& before, const int value);
	void remove_first(const int value);
	void print() const;

private:
	std::shared_ptr<node> first = nullptr;
};



