#include<iostream>
using namespace std;

void swap(int &a, int &b);

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{	
	int mat[4][4] = {
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16},
	};
	
	for(int i = 0;i<4;i++)
	{
		for(int j = 0;j<4;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	
	for (int i = 0;i<4;i++)
	{
		for(int j = i+1; j<4;j++)
		{
			swap(mat[i][j],mat[j][i]);
		}
	}
	for (int i = 0;i<2;i++)
	{
		for(int j = 0; j<4;j++)
		{
			swap(mat[i][j],mat[3-i][j]);
		}
	}
	
	for(int i = 0;i<4;i++)
	{
		for(int j = 0;j<4;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
