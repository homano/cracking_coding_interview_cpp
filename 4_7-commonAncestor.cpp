//Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree.
// Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary
//search tree.


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

void firstCommonAncestor1(Node* head, Node* nd1, Node* nd2, Node* &ans)
{
	if(head == NULL || nd1 == NULL || nd2 == NULL)
		return;
	if(head && father(head, nd1) && father(head, nd2))
	{
		ans = head;
        //cout << ans->key << endl;
		firstCommonAncestor1(head->lchild, nd1, nd2, ans);
		firstCommonAncestor1(head->rchild, nd1, nd2, ans);
	}
}

Node* firstCommonAncestor(Node *head, Node *nd1, Node *nd2)
{
	int dep1 = 0, dep2 = 0;
	while(nd1->parent != NULL)
    {
        nd1 = nd1->parent;
        ++dep1;
    }
	while(nd2->parent != NULL)
    {
        nd2 = nd2->parent;
        ++dep2;
    }
	int diff;
	if (dep1 < dep2)
	{
		diff = dep2 - dep1;
		while(diff > 0)
		{
			nd2 = nd2->parent;
			--diff;
		}
	}
	else if(dep1 > dep2)
	{
		diff =  dep1 - dep2;
		while(diff > 0)
		{
			nd1 = nd1->parent;
			--diff;
		}
	}
	while(nd1->parent != NULL)
	{
		if(nd1->parent == nd2->parent)
			return nd1->parent;
		nd1 = nd1->parent;
		nd2 = nd2->parent;
	}
	return head;
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

int main(){
    int n = 20;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        a[i] = i;
    }
    Node *head = NULL;
    Node *ans = NULL;
    create_minimal_tree(head, NULL, a, 0, n-1);
    Node *nd1 = search(head, 3);
    Node *nd2 = search(head, 6);
    //cout << nd1->key << ' ' << nd2->key << endl;
    //cout << father(head, nd1) << ' ' << father(head, nd2) << endl;
    firstCommonAncestor1(head, nd1, nd2, ans);
    cout << ans->key << endl;
    return 0;
}


