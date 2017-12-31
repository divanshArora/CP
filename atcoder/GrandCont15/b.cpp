
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
	string s;
	cin>>s;
	ll  ans = 0LL;
	ll n = s.length();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='U')
		{
			ans+=(n-i-1);
			ans+=2*(i);
		}
		else
		{
			ans+=2*(n-i-1);
			ans+=i;
		}
	}
	cout<<max(ans,0LL);
	return 0;
}
