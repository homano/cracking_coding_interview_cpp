// check if a list is a palindrome

#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node *next;
}node;

node* init(int a[], int n){
    node *head=NULL, *p;
    for(int i=0; i<n; ++i){
        node *nd = new node();
        nd->data = a[i];
        if(i==0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    return head;
}

int length(node *head)
{	node *p = head;
	int len = 0;
	while(p)
	{
		len++;
        p = p->next;
	}
	return len;
}

bool Compare(node *head1, node *head2)
{
	node *p = head1, *q = head2;
	if(length(p) != length(q))
		return false;
	while(p)
	{
		if(p->data != q->data)
			return false;
        p = p->next;
        q = q->next;
	}
	return true;
}

bool Palindrome(node *head)
{
	node *reverhead = NULL, *p = head;
	while(p)
	{
		node *nd = new node();
        nd->data = p->data;
		nd->next = reverhead;
		reverhead = nd;
        p = p->next;
	}
	return Compare(reverhead, head);
}

int main()
{
	int a[14] = {1,2,3,4,5,6,6,7,6,5,4,3,2,1};
	node *head = init(a, 14);
	cout << Palindrome(head) << endl;
	return 0;
}