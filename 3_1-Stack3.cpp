//use an array to implement three stacks
// for interview purpose, it is enough to know the fixed division
// the flexible division of array space is far more complex to be an interview question
#include <iostream>
using namespace std;

//divide an array equally into 3 parts

class Stack3
{
public:
	Stack3(int size = 300)
	{
		buf = new int[size*3];
		//initiate the top pointers of each stack to be -1
		ptop[0] = ptop[1] = ptop[2] = -1;
	}
	~Stack3()
	{
		delete[] buf;
	}
	void push(int stackNum, int val)
	{
		int idx = stackNum*size + ptop[stackNum] + 1;
		buf[idx] = val;
		++ptop[stackNum];
	}

	int pop(int stackNum)
	{
		int idx = stackNum * size + ptop[stackNum];
		return buf[idx];
		--ptop[stackNum];
	}

	int top(int stackNum)
	{
		int idx = stackNum * size + ptop[stackNum];
		return buf[idx];
	}

	bool empty(int stackNum)
	{
		return ptop[stackNum] == -1;
	}

private:
	int *buf;
	int size;
	int ptop[3];
}