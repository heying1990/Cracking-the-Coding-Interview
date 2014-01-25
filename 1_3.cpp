#include<iostream>
#include<cstring>
using namespace std;

string removeDuplicate(string s);

string removeDuplicate(string s)
{
	unsigned int len = s.length();
	for (unsigned i=0;i<len;i++)
	{
		if(s[i] != '\0')
		{
			char temp = s[i];
			for(unsigned j = 0;j<len;j++)
			{
			   if(s[j] == temp && j !=i)
		  		s[j] = '\0';
			}
		}
	}
	return s;
}

int main()
{
	string s = "ajjigoeiwkk";
	string s1 = removeDuplicate(s);
	cout<<s1<<endl;
}
