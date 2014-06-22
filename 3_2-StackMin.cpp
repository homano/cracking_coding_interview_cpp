// design a stack which has min method which returns the minimum element
// the time complexity should be O(1)

#include <iostream>
using namespace std;

const int MAX_INT = ~(1<<31);//2147483647
// the first method is to record the minimum for each node
typedef struct node{
    int val, min;
}node;

class StackWithMin{
public:
    StackWithMin(int size=1000){
        buf = new node[size];
        buf[0].min = MAX_INT;
        cur = 0;
    }
    ~StackWithMin(){
        delete[] buf;
    }
    void push(int val){
        buf[++cur].val = val;
        if(val<buf[cur-1].min) buf[cur].min = val;
        else buf[cur].min = buf[cur-1].min;
    }
    void pop(){
        --cur;
    }
    int top(){
        return buf[cur].val;
    }
    bool empty(){
        return cur==0;
    }
    int min(){
        return buf[cur].min;
    }
    
private:
    node *buf;
    int cur;
};

// the second method is to have another stack recording the minimum from the current position
// to the bottom of the stack
class Stack
{
public:
	Stack(int size = 1000)
	{
		buf = new int[size];
		//initiate the top pointers the stack to be -1
		cur = -1;
	}
	~Stack()
	{
		delete[] buf;
	}
	void push(int val)
	{
		buf[++cur] = val;
	}
    
	void pop()
	{
		--cur;
	}
    
	int top()
	{
		return buf[cur];
	}
    
	bool empty()
	{
		return cur == -1;
	}
    
private:
	int *buf;
    int cur;
};

class StackWithMin1
{
public:
	StackWithMin1()
	{
        
	}
	~StackWithMin1()
	{
        
	}
    
	void push(int val)
	{
		s1.push(val);
		if(val <= min())
			s2.push(val);
	}
    
	void pop()
	{
		if(s1.top() == min())
			s2.pop();
		s1.pop();
	}
    int top()
    {
        return s1.top();
    }
	int min()
	{
		if(s2.empty())
			return MAX_INT;
		return s2.top();
	}
    
private:
	Stack s1, s2;
};

int main(){
    //cout<<MIN_INT<<endl;
    StackWithMin mystack;//StackWithMin mystack;
    for(int i=0; i<20; ++i)
        mystack.push(i);
    cout<<mystack.min()<<" "<<mystack.top()<<endl;
    mystack.push(-100);
    mystack.push(-100);
    cout<<mystack.min()<<" "<<mystack.top()<<endl;
    mystack.pop();
    cout<<mystack.min()<<" "<<mystack.top()<<endl;
    return 0;
}