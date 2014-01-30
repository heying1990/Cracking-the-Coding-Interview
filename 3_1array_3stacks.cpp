#include<iostream>
using namespace std;

template <class SIT>
class Stack{
public:
	Stack(){
		capacity = 20;
		items = new SIT[3*capacity];
		for(int i = 0;i<3;i++)
			topPtr[i] = -1;
	}
	~Stack(){
		delete[] items;
	}
	bool empty() const;
	void push(const SIT &e, int stackNum){
		if(topPtr[stackNum]==-1)
		{
			topPtr[stackNum]=stackNum*20;//stackNum = 0,1,2 not 1,2,3
			items[topPtr[stackNum]]=e;
		}
		else
		{
			topPtr[stackNum]++;
			items[topPtr[stackNum]]=e;
		}	
	}
	void pop(int stackNum){
		topPtr[stackNum]--;
	}	
	SIT getTop(int stackNum)
	{
		return items[topPtr[stackNum]];
	}
	int getSize(int stackNum)
	{
		return (topPtr[stackNum]-(stackNum)*capacity+1);
	}
private:
	int capacity;
	int topPtr[3];
	SIT *items;
};

int main()
{
	Stack<int> myStack;
	myStack.push(3,0);
	myStack.push(4,1);
	myStack.push(5,2);
	myStack.push(6,0);
	myStack.push(7,1);
	myStack.push(9,1);
	myStack.pop(1);
	cout<<myStack.getTop(0)<<" "<<myStack.getSize(0)<<endl;
	cout<<myStack.getTop(1)<<" "<<myStack.getSize(1)<<endl;
	cout<<myStack.getTop(2)<<" "<<myStack.getSize(2)<<endl;
	return 0;
}
