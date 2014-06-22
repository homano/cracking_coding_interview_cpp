// check if the tree is balanced.
// use checkHeight function to check the height of a tree

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 100;
struct Node{
    int key;
    Node *lchild, *rchild, *parent;
};
Node *head, *p, node[maxn];
int cnt;

void init(){
    head = p = NULL;
    //memset(node, '\0', sizeof(node)); this is not essential
    cnt = 0;
    
}

// the following code with work but everytime you need to start from the head and it
// takes a long time to create the tree. An alternative method is to cut out the
// traversal part and recursively use the createMinimalBST method 

void insert(Node* &head, int x){
    if(head == NULL){
        node[cnt].key = x;
        node[cnt].parent = p;
        head = &node[cnt++];
        return;
    }
    p = head;
    if(x < head->key)
        insert(head->lchild, x);
    else
        insert(head->rchild, x);
}

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

int checkHeight(Node *head)
{
    if(head == NULL) return 0;
    // check if the left subtree is balanced
    int leftHeight = checkHeight(head->lchild);
    if(leftHeight == -1)
        return -1; // not balanced
    //check if the right subtree is balanced
    int rightHeight = checkHeight(head->rchild);
    if(rightHeight == -1)
        return -1; // not balanced
    // check if the current node is balanced
    int heightDiff = leftHeight - rightHeight;
    if(abs(heightDiff) > 1)
        return -1; // not balanced
    else
        return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node *head)
{
    if(checkHeight(head) == -1)
        return false;
    else
        return true;
}

int main(){
    init();
    int a[] = {
        5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12
    };
    for(int i=0; i<12; ++i)
        insert(head, a[i]);
    cout<<isBalanced(head)<<endl;
    return 0;
}