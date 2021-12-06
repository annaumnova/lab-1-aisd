//0301 Umnova variant 3
//L1, methods: 1-12, 14
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "overloading_cout.h"

int main()
{
	setlocale(LC_ALL, "English");

	List list_class_example;//3456
	list_class_example.push_back(4);
	list_class_example.push_back(5);
	list_class_example.push_front(3);
	list_class_example.push_back(6);
	list_class_example.printl1();

	list_class_example.pop_back();//345
	list_class_example.pop_front();//45
	list_class_example.printl1();
	
	list_class_example.insert(8, 1);//485
	list_class_example.printl1();

	list_class_example.remove(0);//85
	list_class_example.printl1();

	std::cout<<"size is: " << list_class_example.get_size() << std::endl;//2

	list_class_example.set(0, 7);//75
	list_class_example.printl1();

	list_class_example.clear();

	std::cout << list_class_example.isEmpty() << std::endl;//0
	list_class_example.printl1();
	//std::cout<<"(overloading) " << list_class_example << std::endl;

	return 0;
}