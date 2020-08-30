#include "linked_list.h"



void linked_list::add(int value)
{
	if (first == nullptr) {
		std::shared_ptr<node> newNode = std::make_shared<node>();
		newNode->value = value;
		
		first = newNode;
		return;
	}


		
	std::shared_ptr<node> current = first;

	while (current->next != nullptr){
		current = current->next;
	}

	std::shared_ptr<node> newNode = std::make_shared<node>();
	newNode->value = value;

	current->next = newNode;
	
}

linked_list::linked_list() {}

linked_list::~linked_list() {}


void linked_list::for_each(const std::function<void(std::shared_ptr<node>)>& action) {
	
	std::shared_ptr<node> current = first;

	while (current != nullptr)
	{
		std::cout << current.use_count();

		action(current);
		current = current->next;
	}
}



const void linked_list::print() {
	for_each([](std::shared_ptr<node> current) {
		std::cout << current->value;
		});
};