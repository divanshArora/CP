
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
	ll n;
	cin>>n;
	ll p2 = 0;
	ll prev = 1;
	ll mod = (ll)1e9+7;
	for(int i=1;i<=n;i++)
	{

		ll np2 =(2*p2%mod + prev%mod)%mod;
		prev = (3*(p2%mod))%mod;
		p2 = np2;
	}
	cout<<prev%mod;
	return 0;
}
