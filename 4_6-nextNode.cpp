//Write an algorithm to find the ‘next’ node (i.e., in-order successor) of a given node in
//a binary search tree where each node has a link to its parent.

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

//if nd has a right subtree, find the left most element of the subtree
Node* minimal(Node* nd)
{
	if(nd == NULL)
		return NULL;
	while(nd->lchild)
	{
		nd = nd->lchild;
	}
	return nd;
}

Node* successor(Node *nd)
{
	if(nd != NULL)
	{
		// if the nd has a right subtree, then find the left-most of that subtree;
		if(nd->rchild)
			return minimal(nd->rchild);
        // if the nd does not have a right tree, then go up until nd is the left node
        // of its parent
		else
        {
            Node * p = nd->parent;
            while(p != NULL)
            {
                if (p->lchild == nd)
                {
                    break;
                }
                nd = p;
                p = p->parent;
            }
            return p;
        }
	}
	return NULL;
	
}

int depthTree(Node *head)
{
	if(head == NULL)
		return 0;
	return max(depthTree(head->lchild), depthTree(head->rchild)) + 1;
}



int main(){
    int n = 6;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        a[i] = i;
    }
    Node *head = NULL;
    create_minimal_tree(head, NULL, a, 0, 5);
    cout << head->key << endl;
    cout << successor(head)->key << endl;
    return 0;
}