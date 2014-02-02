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
bool isAnc(treeNode<T> *root, treeNode<T> *node)
{
	if(root ==NULL||node ==NULL)
		return false;
	if(root==node)
		return true;
	return(isAnc(root->left,node)||isAnc(root->right,node));
}

template <class T>
void findAncestor(treeNode<T> *node1, treeNode<T> *node2, treeNode<T> *root, treeNode<T>* &ans)
{
	if(!isAnc(root,node1)||!isAnc(root, node2))
		return;
	ans=root;
	findAncestor(node1, node2,root->left, ans);
	findAncestor(node1, node2,root->right, ans);
}

int main()
{
	treeNode<int> *root = new treeNode<int>(8);
	root->left = new treeNode<int>(4);
	root->right = new treeNode<int>(12);
	root->left->left = new treeNode<int>(2);
	treeNode<int> *node2 = root->left->right = new treeNode<int>(1);
	treeNode<int> *node1 = root->left->left->left = new treeNode<int>(6);
	root->left->left->right = new treeNode<int>(5);
	root->right->left = new treeNode<int>(11);
	root->right->right = new treeNode<int>(7);
	treeNode<int> *ans;
	findAncestor(node1,node2,root,ans);
	cout<<"ancestor is:"<<ans->data<<endl;
}
