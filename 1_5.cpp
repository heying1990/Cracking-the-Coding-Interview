#include<iostream>
#include<vector>
using namespace std;

vector<char> replaceSpace(string s);


vector<char> replaceSpace(string s)
{
	unsigned int len = s.length();
	vector<char> myvec;
	for (unsigned i = 0;i<len;i++)
	{
		if(s[i] ==' ')
			{
			myvec.push_back('%');
			myvec.push_back('2');
			myvec.push_back('0');
			}
		else
			myvec.push_back(s[i]);
	}
	return myvec;
}

int main()
{
	string s= "test case";
	vector<char> myvec = replaceSpace(s);
	for(unsigned int i = 0;i<myvec.size();i++)
		cout<< myvec[i]<<"";
	cout<<endl;
	return 0;
}
