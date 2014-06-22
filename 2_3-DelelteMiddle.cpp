// implement an algorithm to delete a node in the middle of a single linked list given only the access to that node

#include <iostream>
using namespace std;

void DeleteMiddle(node *middle)
{
	if (!middle -> next)
	{
		cout << "It is wrong node" << endl;
		return;
	}
	middle->data = middle->next->data;
	middle->next = middle->next->next;
}