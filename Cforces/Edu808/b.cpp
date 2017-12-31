
using namespace std;
#include <bits/stdc++.h>
#include <iomanip>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

ll arr[200005];
int main()
{
	ios_base::sync_with_stdio(false);
	ll sm = 0;
	ll n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<k;i++)
	{
		sm+=arr[i];
	}
		vector<ll> ans;

	ans.pb(sm);

	for(int i=k;i<n;i++)
	{
		sm-=arr[i-k];
		sm+=arr[i];
		ans.pb(sm);
	}
	ll finalans =0;
	for(int i=0;i<ans.size();i++)
	{
		finalans+=(ans[i]);
	}
	long double xxx = ((long double)finalans)/((long double)((long double)(n-k+1)));
	cout<<fixed<<setprecision(13) << xxx;
	return 0;
}
