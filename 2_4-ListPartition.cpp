//partition the linked list around value x so the elements less than x are in the front of
// the elements great or equal to x

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

node* ListPartition(node *head, int x)
{
	int count1 = 0, count2 = 0;
	node *head1, *head2, *p, *q;
	while(head)
	{
		node *nd = new node();
		nd->data = head->data;
		if(nd->data < x)
		{
			if (count1 == 0)
			{
				head1 = p = nd;
			}
            else
            {
                p->next = nd;
                p = nd;
            }
			count1++;
		}
		else
		{
			if (count2 == 0)
			{
				head2 = q = nd;
			}
			else
			{
				q->next = nd;
				q = nd;
			}
			count2++;
		}
		head = head->next;
	}
	p->next = head2;
	return head1;
}

int main()
{
	int a[14] = {1,2,3,4,5,6,7,8,9,10,2,3,5,16};
	node *head = init(a, 14);
	int x = 7;
	node *newhead = ListPartition(head, x);
	while(newhead)
	{
		cout << newhead -> data << ' ';
        newhead = newhead -> next;
	}
    cout << endl;
	return 0;
}