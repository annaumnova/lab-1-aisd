#pragma once
#include <iostream>
#include <stdio.h>
#include "class List with functions.cpp"

std::ostream& operator<< (std::ostream& out, const List& l1_list) {
	if (l1_list.get_size() == 0)
		std::cout << "Now list is empty. " << std::endl;
	else
	{
		List::Node* node = l1_list.head;
		out << node->inf << ' ';
		while (node != l1_list.end)
		{
			node = node->next;
			std::cout << node->inf << ' ';
		}
	}
	return out;
}