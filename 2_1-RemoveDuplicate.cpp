//remove the duplicated elements in an unsorted linked list
// if a temporary buffer is no allowed, how would you solve this?


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

void RemoveDuplicate(node *head)
{
    if(head == NULL) return;
	bool hash[100] = {0};
	node *previous = NULL, *n = head;
	while(n != NULL)
	{
		int d =  n->data;
		if (hash[d])
		{
			previous -> next = n -> next;
			n = previous -> next;
		}
		else
		{
			hash[d] = 1;
			previous = n;
			n = n -> next;
		}
	}
}



void RemoveDuplicate1(node* head)
{
    if(head == NULL) return;
	node *current = head, *runner = NULL;
	while(current != NULL)
	{
		runner = current; // this is extremely important. you can set runner = current->next;
		while(runner -> next != NULL)
		{
			if (runner -> next -> data == current -> data)
			{
				runner -> next = runner -> next -> next;
			}
			else
			{
				runner = runner -> next;
			}
		}
		current = current -> next;
	}
}

int main()
{
	int a[14] = {1,2,3,4,5,6,7,8,9,10,2,3,5,16};
	node *head = init(a, 14);
	RemoveDuplicate(head);
	while(head != NULL)
	{
		cout << head -> data << ' ';
        head = head -> next;
	}
    cout << endl;
	return 0;
}