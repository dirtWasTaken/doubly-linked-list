
#include "Linked_List.h"
#include <conio.h>


int main()
{

	/*************************************************************************************
	assigned the templated .h to the handle "Linked" 
	**************************************************************************************/
	Linked_List<int> Linked;

	/*************************************************************************************
	uses the pushfront function to push out those values into our doubly linkled list
	**************************************************************************************/
	Linked.pushFront(1);
	Linked.pushFront(44);
	Linked.pushFront(65);
	Linked.pushFront(14);
	Linked.pushFront(34);
	Linked.pushFront(10);

	/*************************************************************************************
	outputs unsorted list
	**************************************************************************************/
	std::cout << "Linked list before sorting\n\n";
	Linked.printList();

	/*************************************************************************************
	sorts and then outputs the sorted list in order 
	**************************************************************************************/
	Linked.quickSort();
	std::cout << "After sorting\n\n";
	Linked.printList();

	/*************************************************************************************
	searches for a value not in the list
	**************************************************************************************/
	Linked.nodeSeach(55);
	/*************************************************************************************
	searches for a value that is in the list 
	**************************************************************************************/
	Linked.nodeSeach(14);

	_getch();

	return 0;
}
