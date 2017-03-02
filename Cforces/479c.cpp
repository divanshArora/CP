//http://codeforces.com/problemset/problem/479/C

#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define S second
#define F first
using namespace std;

pair<ll,ll> arr[3*((int)1e5)+4];

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		arr[i]={a,b};
	}
	sort(arr,arr+n);
	ll prev = arr[0].S;
	for(int i=1;i<n;i++)
	{
		if(arr[i].S>=prev)
		{
			prev = arr[i].S;
		}
		else
		{
			prev = arr[i].F;
		}
	}
	cout<<prev<<endl;

}






