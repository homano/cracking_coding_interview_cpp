// implement an algorithm to find the kth to last element of a singly linked list

#include <iostream>

using namespace std;

typedef struct node
{
    int data;               // will store information
    node *next;             // the reference to the next node
} node ;

node* init(int a[], int n)
{
	node *head, *p;
	for (int i = 0; i < n; ++i)
	{
		node *nd = new node();
		nd -> data = a[i];
		if(i == 0)
		{
			head = p = nd;
		}
		else
		{
			p -> next = nd;
			p = nd;
		}
	}
	p -> next = NULL;
	return head;
}

node* KthToLast(node *head, int k)
{
	if(head == NULL) return NULL;
	node *p = head, *q = head;
	while(k > 0)
	{
		q = q -> next;
		// check if k is a legitimate number
		if(q == NULL)
			return NULL;
		k--;
	}
	while(q->next != NULL)
	{
		q = q -> next;
		p = p -> next;
	}
	return p;
}

int main()
{
	int a[14] = {1,2,3,4,5,6,7,8,9,10,2,3,5,16};
	int k = 19;
	node *head = init(a, 14);
    if(KthToLast(head, k) == NULL)
        cout << "K is not an valid number" << endl;
	else
        cout << KthToLast(head, k) -> data << endl;
	return 0;
}