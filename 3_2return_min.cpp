#include<iostream>
using namespace std;

struct listNode{
	int data;
	int minToBot=0;
	listNode *next;
	listNode():next(NULL){}
	listNode(int newData):data(newData),next(NULL){}
};

class Stack{
public:
	Stack():top(NULL), size(0){};
	~Stack()
	{
		while(top!=NULL)
			pop();
	}
	bool empty() const;
	void push(const int & e);
	void pop();
	int getTop()
	{
		return top->data;
	}
	int getSize()
	{
		return size;
	}
	int getMin()
	{
		return minNum;
	}
private:
	listNode *top;
	int size;
	int minNum;
};

void Stack::pop(){
	listNode *t = top;
	top = top->next;
	if(t->data < t->minToBot)
		minNum = t->minToBot;
	delete t;
	size--;
}

void Stack::push(const int &d){

	if(top ==NULL)
	{
		top = new listNode(d);
		top->minToBot=top->data;
		size++;
		minNum = top->data;
	}
	else
	{
		listNode *newNode = new listNode(d);
		if(top->data<top->minToBot)
		{
			newNode->minToBot = top->data;
		}
		else
			newNode->minToBot = top->minToBot;
		if(newNode->data < newNode->minToBot)
			minNum = newNode->data;
		newNode->next = top;
		size++;
		top = newNode;
	}
}

int main()
{
	Stack myStack;
	myStack.push(3);
	cout << "min:"<<myStack.getMin() <<endl; 
	myStack.push(5);
	cout << "min:"<<myStack.getMin() <<endl; 
	myStack.push(2);
	cout << "min:"<<myStack.getMin() <<endl; 
	myStack.push(7);
	cout << "min:"<<myStack.getMin() <<endl; 
	myStack.pop();
	cout << "min:"<<myStack.getMin() <<endl;
	myStack.pop();
	cout << "min:"<<myStack.getMin() <<endl; 
	while(myStack.getSize() >0 ){
		cout<<myStack.getTop()<<endl;
		myStack.pop();
	}
	return 0;
}



