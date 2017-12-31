
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
	ll n,m,k;
	cin>>n>>m>>k;
	ll arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		arr[i]*=x;
	}
	cout<<max(*max_element(arr,arr+n)*m,m*k);
	return 0;
}
