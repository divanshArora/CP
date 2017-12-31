
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;


int main()
{
	ios_base::sync_with_stdio(false);
	string s;cin>>s;
	int ind = s.length()+1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0')
		{
			ind = i;break;
		}
	}
	ind  = min(ind,(int)(s.length()-1));
	for(int i=0;i<s.length();i++)
	{
		if(i!=ind)cout<<s[i];
	}

	return 0;
}
