
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

vector <pair <ll , ll >> v;

bool myfun(pair<ll,ll> a, pair<ll,ll> b )
{
	return a.SS<b.SS;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		v.pb({x,y});
	}
	sort(v.begin(),v.end());
	ll a=1,b=1,c=1;
	ll res  = 0;
	for(int i=1;i<n;i++)
	{
		a =1;
		while(i<n && v[i].FF==v[i-1].FF)
		{
			a++;
			i++;
		}
		res+=(a*(a-1))/2;
	}
	for(int i=1;i<n;i++)
	{
		c = 1;
		while(i<n && v[i].SS==v[i-1].SS && v[i].FF==v[i-1].FF)
		{
			c++;
			i++;
		}
		res-= ((c-1)*c)/2;
	}

	sort(v.begin(),v.end(),myfun);
	for(int i=1;i<n;i++)
	{
		b=1;
		while(i<n && v[i].SS==v[i-1].SS)
		{
			b++;
			i++;
		}
		res+=((b-1)*b)/2;
	}
	cout<<res;
	return 0;
}
