#include<iostream>
using namespace std;
const int STACK_SIZE = 3;
const int STACK_NUM = 10;

template<class SIT >
struct listNode{
	SIT data;
	listNode *next;
	listNode():next(NULL){}
	listNode(SIT newData):data(newData),next(NULL){}
};

template<class SIT >
class Stack{
public:
	Stack():top(NULL), size(0),capacity(STACK_SIZE){};
	~Stack()
	{
		while(top!=NULL)
			pop();
	}
	bool empty() const
	{
		if(top ==NULL)
			return true;
		return false;
	}
	bool full() 
	{
		if(size<capacity)
			return false;
		return true;
	}
	void push(const SIT & d)
	{
	listNode<SIT> *newNode = new listNode<SIT>(d);
	newNode->next = top;
	size++;
	top = newNode;
	}
	void pop()
	{
	listNode<SIT> *t = top;
	top = top->next;
	delete t;
	size--;
	}
	SIT getTop()
	{
		return top->data;
	}
	int getSize()
	{
		return size;
	}
private:
	listNode<SIT> *top;
	int size;
	int capacity;
};

template<class SIT>
class SetOfStacks{
public:
	SetOfStacks()
	{
		stacks = new Stack<SIT>[STACK_NUM];
		currStack = 1;
		capacity = STACK_NUM;
	}
	~SetOfStacks()
	{
		delete []stacks;
	}
	void push(const SIT & e)
	{
		if(!stacks[currStack].full())
			stacks[currStack].push(e);
		else
		{
			currStack++;
			stacks[currStack].push(e);
		}
	}
	void pop()
	{
		if(stacks[currStack].empty())
			currStack--;
		stacks[currStack].pop();
	}
	int getStackNum()
	{
		return currStack;
	}
private:
	Stack<SIT> *stacks;
	int currStack;
	int capacity;
};

int main()
{
	SetOfStacks<int> myStackSet;
	myStackSet.push(3);
	myStackSet.push(4);
	myStackSet.push(5);
	cout<<myStackSet.getStackNum()<<endl;
	myStackSet.push(6);
	myStackSet.push(8);
	myStackSet.push(9);
	cout<<myStackSet.getStackNum()<<endl;
	myStackSet.push(0);
	cout<<myStackSet.getStackNum()<<endl;
	myStackSet.pop();
	cout<<myStackSet.getStackNum()<<endl;
	myStackSet.pop();
	myStackSet.pop();
	myStackSet.pop();
	myStackSet.pop();
	myStackSet.pop();
	cout<<myStackSet.getStackNum()<<endl;
	myStackSet.pop();
	return 0;
}


