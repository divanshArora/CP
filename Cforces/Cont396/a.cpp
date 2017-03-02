#include <iostream>
#define F first
#define S second

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string a,b;
	cin>>a>>b;
	if(a.compare(b)==0 || a.compare("")==0 || b.compare("")==0 )
	{
		cout<<-1;
		return 0;
	}
	if(a.length()>b.length())
	{
		cout<<a.length();
	}
	else if(a.length()<b.length())
	{
		cout<<b.length();
	}
	else
	{
		cout<<a.length();
	}

return 0;
} 