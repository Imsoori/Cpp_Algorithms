//10799
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	
	int cnt=0, sum=0;
	
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]=='(')
		{
			cnt++;
		}
		else /// ')'
		{
			cnt--;
			if(s[i-1]=='(')
				sum += cnt;
			else
				sum++;
		}
	}
	
	cout<<sum<<endl;
	return 0;
}