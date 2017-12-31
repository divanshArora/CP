
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;
bool myfunction (ll i,ll j) { return (i>j); }
ll prod[100005];
ll client[100005];
int main()
{
	ios_base::sync_with_stdio(false);
	int n,f;
	cin>>n>>f;
		vector<ll> v;

	for(int i=0;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		prod[i]=a;
		client[i] = b;
	}
	

	ll ans =0;
	for(int i=0;i<n;i++)
	{
		ans+=min(prod[i],client[i]);
		if(prod[i]<client[i])
			{
				if(2*prod[i]<=client[i])
				{
					v.pb(prod[i]);
				}
				else
				{
					v.pb(client[i]-prod[i]);
				}
			}
	}	
	sort(v.begin(),v.end(),myfunction);
	for(int i=0;i<f;i++)
		{
			if(i<v.size())
			ans+=v[i];
		}

	cout<<ans;
	return 0;
}
