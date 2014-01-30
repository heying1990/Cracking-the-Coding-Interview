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
class Queue{
public:
	Queue():entry(NULL), exit(NULL),size(0){};
	~Queue()
	{
		while(exit!=NULL) //check exit instead of entry
		{
			//cout<<"haha ";
			pop();
		}
	}
	bool empty() const;
	void push(const SIT & e);
	void pop();
	SIT getEntry()
	{
		return entry->data;
	}
	SIT getExit()
	{
		return exit->data;
	}
	int getSize()
	{
		return size;
	}
private:
	listNode<SIT> *entry;
	listNode<SIT> *exit;
	int size;
};

template<class SIT>
void Queue<SIT>::push(const SIT & d){
	if(entry ==NULL){
		entry = new listNode<SIT>(d);
		exit = entry;
		size++;
	}
	else{
		listNode<SIT> *t = new listNode<SIT>(d);
		entry->next = t;
		entry = t;
		size++;
	}
}

template<class SIT>
void Queue<SIT>::pop(){
	if(exit == NULL)
	{
		cerr<<"Cannot pop from empty queue"<<endl;
		//exit(1);
	}
	else{
		listNode<SIT> *temp = exit;
		exit = exit->next;
		delete temp;
		size--;
	}
}


int main()
{
	Queue<int> myQueue;
	myQueue.push(3);
	myQueue.push(4);
	myQueue.push(5);
	myQueue.push(6);
	myQueue.push(7);
	cout<<myQueue.getExit()<<endl;
	cout<<myQueue.getEntry()<<endl;
	while(myQueue.getSize() >0 ){
		myQueue.pop();
	}
	//cout<<"haha";
	cout<<myQueue.getSize()<<endl;
	//cout<<"haha";
	return 0;
}











