#include <iostream>
#include <cstdlib>
#include<algorithm>
#include "Linked_List.h"


int main()
{
	
	Linked_List Linked;

	struct Node *a = NULL;
		
	Linked.push(&a, 1);
	Linked.push(&a, 44);
	Linked.push(&a, 65);
	Linked.push(&a, 14);
	Linked.push(&a, 34);
	Linked.push(&a, 10);

	std::cout << "Linked list before sorting\n\n";
	Linked.printList(a);

	Linked.quickSort(a);

	std::cout << "Linked list after sorting\n\n";
	Linked.printList(a);

	Linked.nodeSeach(a, 14);

	Linked.nodeSeach(a, 55);

	return 0;
}
