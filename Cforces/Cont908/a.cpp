
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

char digs[5]={'1','3','5','7','9'}; 
char digs1[5]={'a','e','i','o','u'}; 

bool chk(char c)
{
	for(int i=0;i<5;i++)if(digs[i]==c)return true;
	return false;
}

bool chk1(char c)
{
	for(int i=0;i<5;i++)if(digs1[i]==c)return true;
	return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]<59)
		{
			if(chk(s[i]))ans++;
		}
		else
		{
			if(chk1(s[i]))ans++;	
		}
	}
	cout<<ans<<'\n';
}
