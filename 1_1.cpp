#include<iostream>
#include<vector>
using namespace std;


bool CheckUnique(string s);

int main()
{
	string test="caoguanglei";
	if(!CheckUnique(test))
		cout<<"There is duplicate char"<<endl;
	else
		cout<<"There is no duplicate char"<<endl;
	return 0;		
}

bool CheckUnique(string s)
{
	vector<bool> boolean(256);
	boolean.assign(256, false);
	//bool boolean[256];
	
	unsigned int len = s.length();
	for (unsigned i = 0; i<len; i++)
	{
		int a = (int)s[i];
		if(boolean[a]== false)
			boolean[a] = true;
		else
			return false;
	}
	return true;
}
