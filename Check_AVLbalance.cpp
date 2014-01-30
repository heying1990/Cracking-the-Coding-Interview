#include<iostream>
#include<algorithm>
using namespace std;

template<class T>
struct treeNode{
	T data;
	treeNode *left;
	treeNode *right;
	treeNode(T newData):data(newData),left(NULL),right(NULL){}
};

template<class T>
int getHeight(treeNode<T> *root);
template<class T>
bool checkAVLBalance(treeNode<T> *root);

template<class T>
int getHeight(treeNode<T> *root)
{
	if (root == NULL)
		return 0;
	return max(getHeight(root->left),getHeight(root->right))+1;
	
}
template<class T>
bool checkAVLBalance(treeNode<T> *root)
{
	if(root == NULL)
		return true;
	return (abs(getHeight(root->left)-getHeight(root->right))<2 && checkAVLBalance(root->left) && checkAVLBalance(root->right));
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
	getHeight(root);
	if(checkAVLBalance(root))
		cout<<"the tree is AVL balanced"<<endl;
	else
		cout<<"the tree is AVL unbalanced"<<endl;
}
