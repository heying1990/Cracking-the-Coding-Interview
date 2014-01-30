#include<iostream>
using namespace std;

struct listNode{
	int data;
	listNode *next;
	listNode(int newData):data(newData),next(NULL){}
};

listNode* findNode(listNode *head,int k);

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
	listNode* foundNode = findNode(head,3);
	cout<<foundNode->data<<endl;
}

listNode* findNode(listNode *head, int k)
{
	int len=0;
	listNode *t = head;
	while(t !=NULL)
	{
		len++;
		t = t->next;
	}
	for(int i = 0;i<len-k-1;i++)
	{
		head = head->next;
	}
	return head;
}
