

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


struct Node{
    int key;
    Node *lchild, *rchild, *parent;
};


// the following code with work but everytime you need to start from the head and it
// takes a long time to create the tree. An alternative method is to cut out the
// traversal part and recursively use the createMinimalBST method



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
    int a[] = {
        5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12
    };
    Node *head = createMinimalBST(a, 0, 11);
    cout<<isBalanced(head)<<endl;
    return 0;
}
