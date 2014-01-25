#include<iostream>
#include<cstring>
using namespace std;

string reverse(string s);
void swap(char &a,char &b);

string reverse(char *s)
{
	int len = strlen(s);
	for(int i = 0;i<(len)/2;i++)
		swap(s[i],s[len-1-i]);
	return s;
}

void swap(char &a,char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

int main()
{
	char s[] = "abcdefgh";
	reverse(s);
	cout<<s<<endl;
	return 0;
}
