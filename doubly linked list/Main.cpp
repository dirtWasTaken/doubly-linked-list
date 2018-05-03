
#include "Linked_List.h"
#include <conio.h>


int main()
{

////////////////////////////////////	struct Node *a = NULL;
	
	Linked_List<int> Linked;

	Linked.pushFront(1);
	Linked.pushFront(44);
	Linked.pushFront(65);
	Linked.pushFront(14);
	Linked.pushFront(34);
	Linked.pushFront(10);

	std::cout << "Linked list before sorting\n\n";


	Linked.printList();

	Linked.quickSort();

	std::cout << "After sorting\n\n";

	Linked.printList();

	Linked.nodeSeach(55);

	Linked.nodeSeach(14);

	_getch();

	return 0;
}
