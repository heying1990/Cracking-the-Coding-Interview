#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

struct listNode{
	int data;
	listNode *next;
	listNode(int newData):data(newData),next(NULL){}
};

void removeDuplicate(listNode *head);
void printList(listNode *head);

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
	printList(head);
	removeDuplicate(head);
	cout<<endl;
	printList(head);
	//cout
}

void printList(listNode *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

void removeDuplicate(listNode *head)
{
	unordered_set<int> hashSet;
	hashSet.insert(head->data);
	listNode* prev=head;
	head=head->next;
	while(head!=NULL)
	{
		if(hashSet.find(head->data)==hashSet.end())
		{
			hashSet.insert(head->data);
			prev=head;
			head=head->next;
		}
		else
		{
			prev->next=head->next;
			listNode *tmp=head;
			head=head->next;
			delete tmp;
		}			
	}
}

