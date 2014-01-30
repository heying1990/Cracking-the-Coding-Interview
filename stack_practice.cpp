#include<iostream>
using namespace std;

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
	Stack():top(NULL), size(0){};
	~Stack()
	{
		while(top!=NULL)
			pop();
	}
	bool empty() const;
	void push(const SIT & e);
	void pop();
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
};

template<class SIT>
void Stack<SIT>::pop(){
	listNode<SIT> *t = top;
	top = top->next;
	delete t;
	size--;
}

template<class SIT>
void Stack<SIT>::push(const SIT &d){
	listNode<SIT> *newNode = new listNode<SIT>(d);
	newNode->next = top;
	size++;
	top = newNode;
}



int main()
{
	Stack<int> myStack;
	myStack.push(3);
	myStack.push(4);
	cout<<myStack.getTop()<<endl;
	myStack.push(5);
	myStack.push(6);
	myStack.push(7);
	while(myStack.getSize() >0 ){
		cout<<myStack.getTop()<<endl;
		myStack.pop();
	}
	return 0;
}
