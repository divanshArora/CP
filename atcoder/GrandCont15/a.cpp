
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
	ll n,a,b;
	cin>>n>>a>>b;
	ll minsum = (n-1)*(a) + b; 
	ll maxsum = (n-1)*(b) + a;
	ll ans = maxsum-minsum+1;
	cout<<max(ans,0LL);
	return 0;
}
