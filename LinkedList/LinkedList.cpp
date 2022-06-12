#include <iostream>
#include "List.h"

int main()
{
	List list;
	list.push({ "E3", 1, 2, 4 });
	list.push({ "Q4", 1, 2, 15 });
	list.push({ "T3", 2, 9, 37 });
	list.push({ "UI34", 1, 2, 8 });
	list.push({ "Z4", 1, 2, 15 });
	list.push({ "F22", 2, 6, 37 });

	std::cout << "resistors with an accuracy of better than 5 :" << std::endl;
	list.out(5);

	list.pop_front();
	list.pop_back();

	std::cout << "\n\n Deleting test\n\n";
	list.out(5);
}