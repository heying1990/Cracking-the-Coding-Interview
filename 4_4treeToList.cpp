#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


template <class T>
struct treeNode{
	T data;
	treeNode *left;
	treeNode *right;
	treeNode(T newData):data(newData),left(NULL),right(NULL){}
};

template <class T>
struct listNode{
	T data;
	listNode *next;
	listNode(T newData):data(newData),next(NULL){}
	listNode():next(NULL){}
};
template <class T>
vector<listNode<T> *> createList(treeNode<T> *root)
{
	queue<treeNode<T>*> q;
	q.push(root);
	listNode<T> *curr;
	curr = new listNode<T>(root->data);
	vector<listNode<T>*> depthList;
	depthList.push_back(curr);
	int i = 0;
	listNode<T> * head = NULL;
	while(!q.empty())
	{
		unsigned int len = q.size();
		for(unsigned int j = 0;j<len;j++)
		{
			treeNode<T> *temp = q.front();
			q.pop();
			if(temp->left != NULL)
			{
				if(head ==NULL)
				{
					curr = new listNode<T>(temp->left->data);
					head = curr;
					depthList.push_back(head);
					q.push(temp->left);
					
				}
				else
				{
					curr->next = new listNode<T>(temp->left->data);
                    curr = curr->next;
					//cout<<curr->data<<endl;
					q.push(temp->left);
					
				}
			}
			if(temp->right != NULL)
			{
				if(head ==NULL)
				{
					curr = new listNode<T>(temp->right->data);
					head = curr;
					depthList.push_back(head);
					q.push(temp->right);
					//curr = head->next;
				}
				else
				{
					curr->next = new listNode<T>(temp->right->data);
                    curr = curr->next;
					//cout<<curr->data<<endl;
					q.push(temp->right);
				}
			}
		}
		i++;
		head = NULL;
	}
	return depthList;
}

int main()
{
	treeNode<int> *root = new treeNode<int>(8);
	root->left = new treeNode<int>(4);
	root->right = new treeNode<int>(12);
	root->left->left = new treeNode<int>(2);
	root->left->right = new treeNode<int>(1);
	root->left->left->left = new treeNode<int>(6);
	root->left->left->right = new treeNode<int>(5);
	root->left->left->left->left = new treeNode<int>(7);
	root->left->right->right = new treeNode<int>(3);
	root->right->left = new treeNode<int>(11);
	root->right->right = new treeNode<int>(8);
	root->right->right->right = new treeNode<int>(9);
	vector<listNode<int>*> depthList = createList(root);
	listNode<int> * curr;
	for (unsigned int i=0;i<depthList.size();i++)
	{
		curr = depthList[i];
		cout<<"depth "<<i<<" :"<<endl;
		while(curr != NULL)
		{
			cout<<curr->data<<" "<<endl;
			curr = curr->next;
		}
	}
}
