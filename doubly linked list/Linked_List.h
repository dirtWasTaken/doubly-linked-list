#pragma once
#include <iostream>
#include <cstdlib>
#include <algorithm>

// 'T_' will be the type of the data that will be stored in the linked list
///////////////////////////////template<typename T_>
class Linked_List
{
public:

	Linked_List();

	virtual ~Linked_List();



	/********************************************************************************************************************
	struct node for the nodes of the linked list
	********************************************************************************************************************/
	struct Node
	{
		Node() {}
		Node(int number) { data = number; }
		int data = 0;
/////////////////////////		T_ data;
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
	function definitions 
	********************************************************************************************************************/
	void printList();

	void quickSort();

	void nodeSeach(Node* ptrSearch, int seachValue);

	void swap(int* a, int* b);

	void pushFront(int new_data);

	void _quickSort(struct Node* L, struct Node* h);

	bool sort = false;




private:
	Node *m_head = nullptr;
	Node *m_tail = nullptr;
};

