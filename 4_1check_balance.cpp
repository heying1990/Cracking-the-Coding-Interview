#include<iostream>
#include<algorithm>
using namespace std;


template <class T>
struct treeNode{
	T data;
	treeNode *left;
	treeNode *right;
	treeNode(T newData):data(newData),left(NULL),right(NULL){}
};
template<class T>
void getDepth(treeNode<T> *root, int depth, vector<int> &depthVec);
bool checkBalance(vector<int> depthVec);

template<class T>
void getDepth(treeNode<T> *root, int depth, vector<int> &depthVec)
{
	if(root ==NULL)
		return;
	if(root->left ==NULL && root->right ==NULL)
	{
		depth++;
		depthVec.push_back(depth);
	}
	getDepth(root->left,depth+1,depthVec);
	getDepth(root->right,depth+1,depthVec);
}

bool checkBalance(vector<int> depthVec)
{
	int max = *(max_element(depthVec.begin(),depthVec.end())); //use iterator and max_element in algorithm
	int min = *(min_element(depthVec.begin(),depthVec.end())); //use iterator and max_element in algorithm
	if(max-min >1)
		return false;
	return true;
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
	int depth = 0;
	vector<int> depthVec;
	getDepth(root, depth, depthVec);
		cout<<depthVec.size()<<endl;
	for(unsigned int i = 0;i<depthVec.size();i++)
		cout<<depthVec[i]<<" ";
	cout<<endl;
	if(checkBalance(depthVec))
		cout<<"the tree is balanced"<<endl;
	else
		cout<<"the tree is unbalanced"<<endl;
}
