#include<iostream>
#include<algorithm>
using namespace std;


template <class T>
struct treeNode{
	T data;
	treeNode *left;
	treeNode *right;
	treeNode(T newData):data(newData),left(NULL),right(NULL){}
	treeNode():left(NULL),right(NULL){}
};


treeNode<int> *createTree( int sortedArray[], int start, int end)
{
	if(start > end)
		return NULL;
	int mid = (start+end)/2;
	treeNode<int> *root = new treeNode<int>(sortedArray[mid]);
	root->left = createTree(sortedArray, start, mid-1);
	root->right = createTree(sortedArray,mid+1,end);
	return root;
}
template <class T>
void printTree(treeNode<T> *root)
{
	if(root ==NULL)
		return;
	printTree(root->left);
	cout<<root->data<<endl;
	printTree(root->right);
}
int main()
{
	int sortedArray[] = {1,3,5,6,7,9,10,13,15,18,19,20,21,34};
	treeNode<int> *root = createTree(sortedArray,1,14);
	printTree(root);
}
