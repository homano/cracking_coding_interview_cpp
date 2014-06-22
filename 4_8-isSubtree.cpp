//You have two very large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes.
//Create an algorithm to decide if T2 is a subtree of T1
// 1. one method is to use a string to store the preorder and inorder of T2 and T1.
// if preorder and inorder traversals of t2 are both substrings of those of T1, then t2 is a subtree
// 2. alternaitve method is to visit the t1 node by node and see if any subtree can match t2.

#include <iostream>

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

void create_minimal_tree(Node* &head, Node *parent, int a[], int start, int end)
{
    if(start <= end)
    {
        int mid = (start + end)>>1;
        Node *nd = new Node;
        nd->key = a[mid];
        nd->parent = parent;
        head = nd;
        create_minimal_tree(head->lchild, head, a, start, mid-1);
        create_minimal_tree(head->rchild, head, a, mid+1, end);
    }
}

int depthTree(Node* head)
{
	if(head == NULL)
		return 0;
	return max(depthTree(head->lchild), depthTree(head->rchild)) + 1;
}

bool father(Node* nd1, Node* nd2)
{
	if(nd1 == NULL)
		return false;
	else if(nd1 == nd2)
		return true;
	else return father(nd1->lchild, nd2) || father(nd1->rchild, nd2);
}

Node* search(Node* head, int x)
{
    if(head == NULL)
        return NULL;
    else if(x == head->key)
        return head;
    else if(x <= head->key)
        return search(head->lchild, x);
    else
        return search(head->rchild, x);
    
}

bool matchTree(Node* nd1, Node* nd2)
{
	if(nd1 == NULL && nd2 == NULL)
		return true;
	else if(nd1 == NULL || nd2 == NULL)
		return false;
	else
	{
		if(nd1->key != nd2->key)
			return false;
		return (matchTree(nd1->lchild, nd2->lchild) && matchTree(nd1->rchild, nd2->rchild));
	}
}

bool subTree(Node* nd1, Node* nd2)
{
	if(nd1 == NULL)
		return false;
	if (nd1->key == nd2->key)
	{
		if(matchTree(nd1, nd2))
			return true;
	}
	return (subTree(nd1->lchild, nd2) || subTree(nd1->rchild, nd2));
}

bool containsTree(Node* nd1, Node* nd2)
{
	if(nd2 == NULL)
		return true;
	else
		return subTree(nd1, nd2);
}
int main(){
    int n = 20;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        a[i] = i;
    }
    Node *head = NULL;
    create_minimal_tree(head, NULL, a, 0, n-1);
    Node *nd = new Node;
    nd->key = 28;
    nd->lchild = head;
    cout << containsTree(head, nd) << endl;
    return 0;
}


