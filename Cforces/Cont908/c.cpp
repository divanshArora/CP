
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;


double gety(vector< pair<ll, double > > &v , ll r, ll x)
{
	if(v.size()==0)return ((double)r);
	double minyi = -1.0;
	for(int i=0;i<v.size();i++)
	{
		ll x1 = v[i].FF;
		if(abs(x-x1)<=2*r)
		{
			double yi = v[i].SS + sqrt(4*r*r - (x-x1)*(x-x1));
			if(yi>minyi)
			{
				minyi = yi;
			}
		}
	}
	if(minyi<0)return ((double)r);
	return minyi;
}

int main()
{
	ios_base::sync_with_stdio(false);
	ll n,r;
	cin>>n>>r;
	vector< pair<ll, double >> v;
	for(int i=0;i<n;i++)
	{
		ll xi;cin>>xi;
		v.pb({xi,gety(v,r,xi)});
	}
	for(int i=0;i<v.size();i++)
	{
		cout.precision(17);
		cout<<fixed<<v[i].SS<<" ";
	}

	return 0;
}
