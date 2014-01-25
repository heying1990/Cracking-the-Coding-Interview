#include<iostream>
using namespace std;

bool checkRotate(string s1, string s2);
bool isSubstring(string s1, string s2);

int main()
{
	string s1 = "heying";
	string s2 = "eyingh";
	if(checkRotate(s1,s2))
		cout<<"two strings are rotate string"<<endl;
	else
		cout<<"are not"<<endl;
}

bool checkRotate(string s1, string s2)
{
	string s3 = s1+s1;
	return isSubstring(s3,s2);
}

bool isSubstring(string s1, string s2)
{
	if(s1.find(s2) != string::npos) return true;
	else return false;
}
