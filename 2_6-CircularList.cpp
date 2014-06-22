//circular list, find the entrance node of the circular list
//由于C++标准中没有哈希表的操作，我用map simulate。but hash table's push and pop operation
//is O(1) while Map is a RB tree and to maintain RB tree, it takes more time to push and pop.
//tree，插入和取值都会花更多的时 间
#include <iostream>
#include <map>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node;

node* init(int a[], int n, int m){
    node *head, *p, *q;
    for(int i=0; i<n; ++i){
        node *nd = new node();
        nd->data = a[i];
        if(i==m) q = nd;
        if(i==0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    p->next = q;
    return head;
}

node* loopstart(node *head){
    if(head==NULL) return NULL;
    node *fast = head, *slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow) break;
    }
    if(!fast || !fast->next) return NULL;
    slow = head;
    while(fast!=slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

// I haven't got the following method work. I don't know where it goes wrong
map<node*, bool> hash;
node* loopstart1(node *head){
    while(head){
        if(hash[head]) return head;
        else{
            hash[head] = true;
            head = head->next;
        }
    }
    return head;
}
int main(){
    int n = 10, m = 9;// m<n
    int a[] = {
        3, 2, 1, 3, 5, 6, 2, 6, 3, 1 
    };
    node *head = init(a, n, m);
    //node *p = loopstart(head);
    node *p = loopstart(head);
    if(p)
        cout<<p->data<<endl;
    return 0;
}