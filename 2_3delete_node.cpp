#include<iostream>
using namespace std;

struct listNode{
	int data;
	listNode *next;
	listNode(int newData):data(newData),next(NULL){}
};

void deleteNode(listNode *curr);

void deleteNode(listNode *curr)
{
	if(curr->next == NULL)
	{
		delete curr;
		curr = NULL;
		
	}
	else
	{
		int temp = curr->data;
		curr-> data = curr->next->data;
		curr->next->data = temp;
		listNode *tmp = curr->next;
		curr->next = tmp->next;
		delete tmp;
		
	}
}

int main()
{
	int list[8] = {2,3,4,1,5,2,5,6};
	listNode *t = new listNode(list[0]);
	listNode *head = t;
	for(int i = 1;i<8;i++)
	{	
		t->next = new listNode(list[i]);
		t = t->next;
	}
	listNode *curr = head;
	for (int i = 1;i<5;i++)
		curr = curr->next;
	deleteNode(curr);
	t = head;
	while(t != NULL)
	{
		cout<<t->data<<" ";
		t = t->next;
	}
	cout<<endl;
	return 0;
}
