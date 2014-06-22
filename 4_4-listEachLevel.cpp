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

vector<list<Node*>> listEachLevel(Node *head)
{
    vector<list<Node*>> ptrs;
    if(head == NULL)
    {
        ptrs.push_back(NULL);
        return ptrs;
    }
    int level = 0;
    list<Node*> li;
    li.push_back(head);
    ptrs.push_back(li);
    while(!ptrs[level].empty())
    {
    	list<Node*> l;
    	list<Node*> :: iterator it;
    	for (it = ptrs[level].begin(); it != ptrs[level].end(); ++it)
    	{
    		Node *n = *it;
    		if(n->lchild) l.push_back(n->lchild);
    		if(n->rchild) l.push_back(n->rchild);
    	}
    	++level;
    	ptrs.push_back(l);
    }
    return ptrs;
}


int main(){
    int n = 6;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        a[i] = i;
    }
    Node *head = createMinimalBST(a, 0, n-1);
    vector<list<Node*>> ptrs = listEachLevel(head);
    for (int i = 0; i < ptrs.size(); ++i) {
        list<Node*> li = ptrs[i];
        list<Node*> :: iterator it;
        for(it = li.begin(); it != li.end(); ++it)
        {
            //Node *n = *it;
            cout << (*it)->key << ' ';
        }
        cout << endl;

    }
    return 0;
}