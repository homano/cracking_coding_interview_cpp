//You are given a binary tree in which each node contains a value. Design an algorithm to print all paths
//which sum up to that value. Note that it can be any path in the tree - it does not have to start at the
//root.

#include <iostream>
#include <vector>
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


void print(Node* head, int level){
    vector<int> v;
    for(int i=0; i<level; ++i){
        v.push_back(head->key);
        head = head->parent;
    }
    while(!v.empty()){
        cout<<v.back()<<" ";
        v.pop_back();
    }
    cout<<endl;
}
void find_sum(Node* head, int sum){
    if(head == NULL) return;
    Node *no = head;
    int tmp = 0;
    for(int i=1; no!=NULL; ++i){
        tmp += no->key;
        if(tmp == sum)
            print(head, i);
        no = no->parent;
    }
    find_sum(head->lchild, sum);
    find_sum(head->rchild, sum);
}
void print2(vector<int> v, int level){
    for(int i=level; i<v.size(); ++i)
        cout<<v.at(i)<<" ";
    cout<<endl;
}
void find_sum2(Node* head, int sum, vector<int> v, int level){
    if(head == NULL) return;
    v.push_back(head->key);
    int tmp = 0;
    for(int i=level; i>-1; --i){
        tmp += v.at(i);
        if(tmp == sum)
            print2(v, i);
    }
    vector<int> v1(v), v2(v);
    find_sum2(head->lchild, sum, v1, level+1);
    find_sum2(head->rchild, sum, v2, level+1);
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
    vector<int> v;
    find_sum2(head, 23, v, 0);
    return 0;
}


