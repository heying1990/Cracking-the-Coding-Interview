#include<iostream>
using namespace std;

struct listNode{
	int data;
	listNode *next;
	listNode():next(NULL){}
	listNode(int newData):data(newData),next(NULL){}
};

listNode* addTwoList(listNode *l1, listNode *l2);

listNode* addTwoList(listNode *l1, listNode *l2)
{
	//listNode *addSum = new listNode();
	listNode *addSum=NULL;
	listNode *head=NULL;
	int add1 = 0;
	while(l1 != NULL && l2 != NULL)
	{
		if(head==NULL)
			head=addSum=new listNode();
		else
		{
			addSum->next=new listNode();
			addSum=addSum->next;
		}
		if(l1->data+l2->data+add1 >9)
		{
			addSum->data = (l1->data+l2->data+add1)%10;
			add1 = 1;
		}
		else
		{
			addSum->data = (l1->data+l2->data+add1)%10;
			add1 = 0;
		}
		//addSum ->next = new listNode();
		//addSum = addSum->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	while(l1 != NULL)
	{
		addSum->next = new listNode();
		addSum = addSum->next;
		addSum->data = l1->data;
		l1 = l1->next;
	}
	while(l2 != NULL)
	{
		addSum->next = new listNode();
		addSum = addSum->next;
		addSum->data = l2->data;
		l2 = l2->next;
	}
	//delete addSum;
	//addSum = NULL;
	return head;
}


int main()
{
	int l1[3] = {2,3,4};
	int l2[5] = {8,8,2,4,5};
	listNode *list1 = new listNode(l1[0]);
	listNode *list2 = new listNode(l2[0]);
	listNode *head1 = list1;
	listNode *head2 = list2;
	for(int i = 1;i<3;i++)
	{	
		list1->next = new listNode(l1[i]);
		list1 = list1->next;
	}
	for(int i = 1;i<5;i++)
	{	
		list2->next = new listNode(l2[i]);
		list2 = list2->next;
	}
	listNode* addSum = addTwoList(head1,head2);
	while(addSum != NULL)
	{
		cout<<addSum->data<<" ";
		addSum = addSum->next;
	}
	cout<<endl;
}
