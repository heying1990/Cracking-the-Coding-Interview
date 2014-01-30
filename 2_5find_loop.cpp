#include<iostream>
#include<unordered_set>
using namespace std;

struct listNode{
	int data;
	listNode *next;
	listNode():next(NULL){}
	listNode(int newData):data(newData),next(NULL){}
};

listNode* findLoop(listNode *head);

listNode* findLoop(listNode *head)
{
	unordered_set<listNode*> table;
	table.insert(head);
	head = head->next;
	while(head != NULL)
	{
		if(table.find(head) != table.end()) //found
		{
			return head;
		}
		else
		{
			table.insert(head);
			head = head->next;
		}
	}
	return NULL;
}

int main()
{
	int list[8] = {2,3,4,1,5,2,5,6};
	listNode *t = new listNode(list[0]);
	listNode *loopStart = new listNode();
	int startPoint = 4;
	listNode *head = t;
	for(int i = 1;i<8;i++)
	{
		if(startPoint==0)
			loopStart = t;	
		t->next = new listNode(list[i]);
		t = t->next;
		startPoint--;
	}
	t->next = loopStart;
	listNode *startFound = findLoop(head);
	if(startFound == NULL)
		cout<<"no loop"<<endl;
	else
		cout<<startFound->data<<endl;
}
