//0301 Umnova variant 3
//L1, methods: 1-12, 14
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "overloading_cout.h"

int main()
{
	List list_class_example;
	List list_1; list_1.push_front(2); list_1.push_back(9);
	list_class_example.push_back(4);
	list_class_example.push_back(5);
	//list_class_example.push_front(3);
	list_class_example.insert_14(list_1, 0);
	//list_class_example.insert(8, 2);
	//list_class_example.printl1();
	std::cout << list_class_example << std::endl;
	
	return 0;
}