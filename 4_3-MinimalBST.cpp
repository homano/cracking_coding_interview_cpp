// use a sorted array (increasing order) to create a binary search tree
// with miminal height

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

void inorderTraversal(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    inorderTraversal(head->lchild);
    cout << head->key << ' ';
    inorderTraversal(head->rchild);
}

void preorderTraversal(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->key << ' ';
    preorderTraversal(head->lchild);
    preorderTraversal(head->rchild);
}

void postorderTraversal(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    postorderTraversal(head->lchild);
    postorderTraversal(head->rchild);
    cout << head->key << ' ';
}

int main(){
    int n = 6;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        a[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    Node *head = createMinimalBST(a, 0, n-1);
    inorderTraversal(head);
    cout << endl;
    preorderTraversal(head);
    cout << endl;
    postorderTraversal(head);
    cout << endl;
    return 0;
}