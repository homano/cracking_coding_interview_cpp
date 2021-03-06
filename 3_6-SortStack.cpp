//sort the stack in ascending order
// the largest element is on the top

#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

void Qsort(stack<int> &s){
    priority_queue< int,vector<int>,less<int> > q;
    // if it is greater, then the smallest element is always on the top
    // if it is less, then the largest element is always on the top
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    while(!q.empty()){
        s.push(q.top());
        q.pop();
    }
}

stack<int> Ssort(stack<int> s){
    stack<int> t;
    while(!s.empty()){
        int data = s.top();
        s.pop();
        while(!t.empty() && t.top()>data){
            s.push(t.top());
            t.pop();
        }
        t.push(data);
    }
    return t;
}
int main(){
    srand((unsigned)time(0));
    stack<int> s;
    
    for(int i=0; i<10; ++i)
        s.push((rand()%100));
    //s = Ssort(s);
    Qsort(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}