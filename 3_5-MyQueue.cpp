//use two stacks to implement a queue

#include <iostream>
#include <stack>
using namespace std;


template <typename T>
class MyQueue
{
public:
	MyQueue(){}
	~MyQueue(){}
	void push(T val)
	{
		sin.push(val);
	}
	void pop()
	{
		if (!sout.empty())
			sout.pop();
		else
		{
			move();
			sout.pop();
		}
	}
	T top()
	{
		if(!sout.empty())
			return sout.top();
		else
		{
			move();
			return sout.top();
		}
	}
    T sintop()
    {
        if (sin.empty()) {
            return -1;
        }
        else
            return sin.top();
    }
	void move()
	{
		while(!sin.empty())
		{
			sout.push(sin.top());
			sin.pop();
		}
	}
private:
	stack<T> sin, sout;
};

int main(){
    MyQueue<int> q;
    for(int i=0; i<10; ++i){
        q.push(i);
    }
    q.pop();
    q.pop();
    q.push(10);
    cout<< q.sintop() << ' ' << q.top() << endl;
    return 0;
}