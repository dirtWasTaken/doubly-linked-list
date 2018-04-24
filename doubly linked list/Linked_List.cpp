
#include "Linked_List.h"




Linked_List::Linked_List()
{
}


Linked_List::~Linked_List()
{
}



/********************************************************************************************************************

********************************************************************************************************************/
void Linked_List::pushFront(int new_data)
{
	struct Node* new_node = new Node;
	new_node->data = new_data;

	if (m_head == NULL)
	{
		// First node in the list
		new_node->next = nullptr;
		new_node->prev = nullptr;
		m_head = new_node;
		m_tail = new_node;
	}
	else
	{
		// All subsequent nodes
		new_node->next = m_head;
		new_node->prev = nullptr;
		m_head->prev = new_node;
		m_head = new_node;
	}

}
/********************************************************************************************************************
seach of the the linked list
********************************************************************************************************************/
void Linked_List::nodeSeach(Node* ptrSeach, int searchValue)
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
void Linked_List::swap(int* a, int* b)
{
	int t = *a;      *a = *b;       *b = t;
}

/********************************************************************************************************************
sorting function
********************************************************************************************************************/
void Linked_List::_quickSort(struct Node* l, struct Node* h)
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
void Linked_List::printList()
{
	Node * temp = m_head;
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
void Linked_List::quickSort()
{
	// Find last node
	struct Node *h = lastNode(m_head);

	// Call the recursive QuickSort
	_quickSort(m_head, h);
}

