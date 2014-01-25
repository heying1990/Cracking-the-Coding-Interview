#include<iostream>
using namespace std;

void setZero(int mat[][4], int row, int col);

int main()
{
	int mat[3][4] = {
	{1,2,0,4},
	{5,6,7,7},
	{9,7,11,12},
	};
	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<4;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	setZero(mat,3,4);
	for(int i = 0;i<3;i++)
		{
			for(int j = 0;j<4;j++)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}
	return 0;
}

void setZero(int mat[][4], int row, int col)
{
	int a[row+col];
	for (int i = 0;i<7;i++)
		a[i] = 0;
	for (int i = 0;i<row;i++)
	{
		for(int j = 0;j<col;j++)
		{
			if(mat[i][j]== 0)
			{
				a[i] = 1;
				a[j+3] = 1;
			}
			
		}
	}
	for (int i = 0;i<row;i++)
	{
		if(a[i] ==1)
		{
			for(int j = 0;j<col;j++)
			{
				mat[i][j] = 0;
			}	
		}
	}
	for (int i = 0;i<col;i++)
	{
		if(a[i+row] ==1)
		{
			for(int j = 0;j<row;j++)
			{
				mat[j][i] = 0;
			}	
		}
	}
}
