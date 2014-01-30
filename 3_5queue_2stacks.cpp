#include<stack>
#include<iostream>
using namespace std;

template<class SIT>
class MyQueue{
private:
	stack<SIT> st1;//in 
	stack<SIT> st2;//out
	int size;
public:
	MyQueue():size(0){};
	~MyQueue()
	{
		while(!empty()) //check exit instead of entry
		{
			//cout<<"haha ";
			st1.pop();
			st2.pop();
		}
	}
	bool empty()
	{
		if(st1.empty()&&st2.empty())
			return true;
		return false;
	}
	void push(const SIT & e)
	{
		st1.push(e);
		size++;
	}
	void pop()
	{
		while(!st1.empty())
		{
			SIT tmp1 = st1.top();
			st1.pop();
			st2.push(tmp1);
			
		}
		st2.pop();
		while(!st2.empty())
		{
			SIT tmp2 = st2.top();
			st2.pop();
			st1.push(tmp2);
		}
		size--;
	}
	int getSize()
	{
		return size;
	}
	SIT getTop()
	{
		return st1.top();
	}
};

int main()
{
	MyQueue<int> myQueue;
	myQueue.push(3);
	myQueue.push(4);
	myQueue.push(5);
	myQueue.push(6);
	myQueue.push(7);
	cout<<"size:"<<myQueue.getSize()<<endl;
	while(!myQueue.empty()){
		cout<<myQueue.getTop()<<" ";
		myQueue.pop();
	}
	cout<<"size:"<<myQueue.getSize()<<endl;
	cout<<endl;
	return 0;
}
