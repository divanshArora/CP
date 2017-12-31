
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

ll arr[100001]={0};
int main()
{
	ios_base::sync_with_stdio(false);
	ll a,b,c;
	
	ll ans = 0;
	ll aaa=0;
	cin>>a>>b>>c;
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		arr[i]= x;
		if(x>b && x<c)
		{
			ans++;
		}
		if(x==a)aaa++;
	}
	ans = max(ans,aaa);
	cout<<ans;
}
