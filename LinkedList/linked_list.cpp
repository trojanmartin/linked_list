#include "linked_list.h"

void linked_list::add(const int value)
{
	if (first == nullptr) {
		first = std::make_shared<node>();
		first->value = value;		
		return;
	} 
	std::shared_ptr<node> current = first;

	while (current->next != nullptr) {
		current = current->next;
	}
	insert_node(current, value);
}

linked_list::linked_list() {}

linked_list::~linked_list() {
	
}

std::shared_ptr<node> linked_list::insert_node(std::shared_ptr<node> &before ,const int value) {
	before->next = std::make_shared<node>();
	before->next->value = value;
	return before->next;
}

void linked_list::remove_first(const int value){
	
}


void linked_list::insert_after(const int value, const int after) {
	std::shared_ptr<node> current = first;

	while (current != nullptr) {
		if (current->value == after) {
			auto afterNew = std::move(current->next);
			linked_list::insert_node(current, value)->next = std::move(afterNew);
			break;
		}
		current = current->next;
	}

}


void linked_list::for_each(std::function<void(std::shared_ptr<node>)>const& action) const {
	
	std::shared_ptr<node> current = first;

	while (current != nullptr)	{
		action(current);
		current = current->next;
	}
}
void linked_list::print() const  {
	for_each([](std::shared_ptr<node> current) {
		std::cout << current->value;
		});
};