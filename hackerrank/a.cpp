
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

int fn(char c)
{
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y' )
	{
		return 1;
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin>>s;
	for(int i=1;i<s.size();i++)
	{	
		if(s[i]==s[i-1] || (fn(s[i])+fn(s[i-1]))== 2)
		{
			cout<<"No";
			return 0;
		}
	}		
	cout<<"Yes";
	return 0;
}
