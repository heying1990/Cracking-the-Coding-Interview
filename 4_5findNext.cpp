#include<iostream>
#include<algorithm>
using namespace std;


template <class T>
struct treeNode{
	T data;
	treeNode *left;
	treeNode *right;
	treeNode *parent;
	treeNode(T newData):data(newData),left(NULL),right(NULL),parent(NULL){}
};
template <class T>
treeNode<T> *findNext(treeNode<T> *target);
template <class T>
treeNode<T> *findNext(treeNode<T> *target)
{
	if(target == NULL)
		return NULL;
	else if(target->right != NULL)
	{
		treeNode<T> *temp = target->right;
		while(temp->left != NULL)
			temp = temp->left;
		return temp;
	}
	treeNode<T> *temp = target->parent;
	while(temp != NULL && temp->data <=target->data)
	{
		target = temp;
		temp = temp->parent;
	}
	return temp;
}


int main()
{
	treeNode<int> *root =new treeNode<int>(6);
	root->left = new treeNode<int>(3);
	root->left->parent = root;
	root->right = new treeNode<int>(9);
	root->right->parent = root;
	root->left->left = new treeNode<int>(2);
	root->left->left->parent = root->left;
	root->left->right = new treeNode<int>(4);
	root->left->right->parent = root->left;
	root->right->left = new treeNode<int>(8);
	root->right->left->parent = root->right;
	root->right->right = new treeNode<int>(10);
	root->right->right->parent = root->right;

	treeNode<int> *target, *tarnext;
	target =root;
	tarnext = findNext(target);
	cout<<"target is:"<<target->data<<endl;
	cout<<"the next is:"<<tarnext->data<<endl;
	target =root->left->right;
	tarnext = findNext(target);
	cout<<"target is:"<<target->data<<endl;
	cout<<"the next is:"<<tarnext->data<<endl;
	target =root->left->left;
	tarnext = findNext(target);
	cout<<"target is:"<<target->data<<endl;
	cout<<"the next is:"<<tarnext->data<<endl;
}
