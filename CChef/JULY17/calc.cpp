
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll n,b;
		cin>>n>>b;
		ll k = n/(2*b);
		ll ans = 0;
		ans= n*k - k*k*b;
		k++;
		if(n-b*k>=0)
		{
			ans = max(ans,n*k - k*k*b);
		}
		ans = max(ans, n-b);
		cout<<max(ans,0LL)<<'\n';
	}
}
