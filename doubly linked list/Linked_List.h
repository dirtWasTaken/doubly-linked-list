#pragma once
#include <iostream>
#include <cstdlib>
#include <algorithm>

// 'T_' will be the type of the data that will be stored in the linked list
template<typename T_> 
class Linked_List
{
public:

	Linked_List() {}

	virtual ~Linked_List(){}



	/********************************************************************************************************************
	struct node for the nodes of the linked list
	********************************************************************************************************************/
	struct Node
	{
		Node() {}
		Node(int number) { data = number; }
		T_ data = 0;
		Node* next = nullptr;
		Node* prev = nullptr;
	};

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
//////////////////////		T_ x = h->data;

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
	uses the value the pushFront function call in main and inserts it into the linked list, if it's the first value,
	it assigns that as the head pointer otherwise subsequent values are inserted sequentially into the list.
	********************************************************************************************************************/
	void pushFront(int new_data)
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
	void nodeSeach(int searchValue)
	{
		struct Node * searchptr = m_head;


		while (searchptr != NULL)
		{
			if (searchptr->data == searchValue)
			{
				std::cout << searchValue << " is in this list \n\n";
				break;
			}
			else
			{
				(searchptr = searchptr->next);
			}
		}
		if (searchptr == NULL)
			{
				std::cout << searchValue << " is not in this list \n\n";
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
	printing function 
	********************************************************************************************************************/
	void printList()
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
	The main function to sort a linked list. It mainly calls _quickSort
	********************************************************************************************************************/
	void quickSort()
	{
		// Find last node
		struct Node *h = lastNode(m_head);

		// Call the recursive QuickSort
		_quickSort(m_head, h);
	}


	bool sort = false;

private:

	/*************************************************************************************
	Head a tail pointer declarations
	**************************************************************************************/
	Node *m_head = nullptr;
	Node *m_tail = nullptr;
};

