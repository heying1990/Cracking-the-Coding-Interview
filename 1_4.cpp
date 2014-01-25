#include<iostream>
#include<vector>
using namespace std;

bool checkAnagram(string a, string b);

bool checkAnagram(string a, string b)
{
	if(a.length() != b.length())
		return false;
	else
	{
		vector<int> freqa(256);
		freqa.assign(256,0);
		vector<int> freqb(256);
		freqb.assign(256,0);
		for (unsigned i = 0;i<a.length();i++)
		{
			int temp = (int)a[i];
			freqa[temp]++;
		}
		for (unsigned i = 0;i<b.length();i++)
		{
			int temp = (int)b[i];
			freqb[temp]++;
		}
		if(freqa == freqb)
			return true;
		else
			return false;
	}
}

int main()
{
	string a = "abcde";
	string b = "edcba";
	if(checkAnagram(a,b))
		cout<<"anagram"<<endl;
	else
		cout<<"not anagram"<<endl;
	return 0;
}
