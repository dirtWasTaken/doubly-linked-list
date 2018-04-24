
#include "Linked_List.h"
#include <conio.h>


int main()
{

////////////////////////////////////	struct Node *a = NULL;
	
	Linked_List Linked;

	Linked.pushFront(1);
	Linked.pushFront(44);
	Linked.pushFront(65);
	Linked.pushFront(14);
	Linked.pushFront(34);
	Linked.pushFront(10);

	std::cout << "Linked list before sorting\n\n";


	Linked.printList();

	//Linked.quickSort(a);

	//std::cout << "Linked list after sorting\n\n";
	//Linked.printList(a);

	//Linked.nodeSeach(a, 14);

	//Linked.nodeSeach(a, 55);

	_getch();

	return 0;
}
