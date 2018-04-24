#include <iostream>
#include <cstdlib>
#include<algorithm>
/********************************************************************************************************************
struct node for the nodes of the linked list
********************************************************************************************************************/

struct Node
{
	int data;
	Node* next;
	Node* prev;
};
/********************************************************************************************************************
function definitions for printing the nodes in forawrd and reverse order
********************************************************************************************************************/
void printList(Node* head);

void quickSort(Node* head);

void nodeSeach(Node* ptrSearch, int seachValue);

bool sort = false;
/********************************************************************************************************************
seach of the the linked list 
********************************************************************************************************************/
void nodeSeach(Node* ptrSeach, int searchValue)
{
	if (ptrSeach == NULL)
		{
			std::cout << searchValue << " is not in this list \n\n";
		}
		else if (ptrSeach->data == searchValue)
		{
			std::cout << searchValue << " is in this list \n\n";
		}
		else
		{
			nodeSeach(ptrSeach->next, searchValue);
		}

}
/********************************************************************************************************************
Swaps two elements of the linked list and used in main
********************************************************************************************************************/
void swap(int* a, int* b)
{
	int t = *a;      *a = *b;       *b = t;
}
/********************************************************************************************************************
finds the last node of the linked list base on the root pointer
********************************************************************************************************************/
struct Node *lastNode(Node *root)
{
	while (root && root->next)
		root = root->next;
	return root;
}
/********************************************************************************************************************
Considers last element as pivot, places the pivot element at its
correct position in sorted array, and places all smaller (smaller than
pivot) to left of pivot and all greater elements to right of pivot
********************************************************************************************************************/
Node* partition(Node *l, Node *h)
{

	int x = h->data;

	Node *i = l->prev;
	for (Node *j = l; j != h; j = j->next)
	{
		if (j->data <= x)
		{
			i = (i == NULL) ? l : i->next;

			swap(&(i->data), &(j->data));
		}
	}
	i = (i == NULL) ? l : i->next;
	swap(&(i->data), &(h->data));
	return i;
}
/********************************************************************************************************************
sorting function
********************************************************************************************************************/
void _quickSort(struct Node* l, struct Node* h)
{
	if (h != NULL && l != h && l != h->next)
	{
		struct Node *p = partition(l, h);
		_quickSort(l, p->prev);
		_quickSort(p->next, h);
	}
}
/********************************************************************************************************************

********************************************************************************************************************/
void printList(Node* head)
{
	Node * temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << "\n\n";
}
/********************************************************************************************************************

********************************************************************************************************************/
// The main function to sort a linked list. It mainly calls _quickSort()
void quickSort(struct Node *head)
{
	// Find last node
	struct Node *h = lastNode(head);

	// Call the recursive QuickSort
	_quickSort(head, h);
}
/********************************************************************************************************************

********************************************************************************************************************/
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node;
	new_node->data = new_data;


	new_node->prev = NULL;

	new_node->next = (*head_ref);

	if ((*head_ref) != NULL) (*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}
int main()
{
	/********************************************************************************************************************
	pointer declarations
	********************************************************************************************************************/
	struct Node *a = NULL;

	push(&a, 1);
	push(&a, 44);
	push(&a, 65);
	push(&a, 14);
	push(&a, 34);
	push(&a, 10);

	std::cout << "Linked list before sorting\n\n";
	printList(a);

	quickSort(a);

	std::cout << "Linked list after sorting\n\n";
	printList(a);

	nodeSeach(a, 14);


	nodeSeach(a, 55);

	return 0;
}
