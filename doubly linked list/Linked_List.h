#pragma once


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
		int data;
		Node* next;
		Node* prev;
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
	void printList(Node* head);

	void quickSort(Node* head);

	void nodeSeach(Node* ptrSearch, int seachValue);

	void swap(int* a, int* b);

	void push(Node** head_ref, int new_data);

	void _quickSort(struct Node* L, struct Node* h);

	bool sort = false;
};

