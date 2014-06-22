//implement an algorithm to check if a binary tree is a binary search tree

// create a linkedlist of all the nodes at each depth of a binary tree.

#include <iostream>
#include <vector>
#include <list>
#include <cstring>
using namespace std;

struct Node{
    int key;
    Node *lchild, *rchild, *parent;
};


Node* createMinimalBST(int a[], int start, int end)
{
    if(start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *nd =  new Node;
    nd->key = a[mid];
    nd->lchild = createMinimalBST(a, start, mid - 1);
    nd->rchild = createMinimalBST(a, mid + 1, end);
    return nd;
}

void create_minimal_tree(Node* &head, Node *parent, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        Node *nd = new Node;
        nd->key = a[mid];
        nd->parent = parent;
        head = nd;
        create_minimal_tree(head->lchild, head, a, start, mid-1);
        create_minimal_tree(head->rchild, head, a, mid+1, end);
    }
}
int depthTree(*Node head)
{
	if(head == NULL)
		return 0;
	return max(depthTree(head->lchild), depthTree(head->rchild)) + 1;
}

bool isBinarySearch(Node* head)
{
	if (depthTree(head) <= 1)
	{
		return true;
	}
	if (head->lchild != NULL && head->lchild->key > head->key)
	{
		return false;
	}
    if (head->rchild != NULL && head->rchild->key <= head->key)
    {
        return false;
    }
    return true;
}



int main(){
    int n = 6;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        a[i] = i;
    }
    Node *head = createMinimalBST(a, 0, n-1);
  
    cout << 
    return 0;
}