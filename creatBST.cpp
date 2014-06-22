#include <iostream>

using namespace std;

struct Node
{
	int key;
	Node *lchild, *rchild, *parent;
};

void createBST(Node* head, Node* parent, int a[], int low, int high){
	if (high >= low){
		int mid =  (low + high)/2;
		Node *nd = new Node();
		nd->key = a[mid];
		
	}
}