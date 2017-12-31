
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;



std::vector<pair<int,int>> v;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n,p;
	ll sum= 0;
	cin>>n>>p;
	for(int i=0;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		v.pb({a,b});
		sum+=a;
	}
	if(sum<=p)
	{
		cout<<"-1";
		return 0;
	}
	double l=0,r=1e17, mid;

	while(r-l>=1e-8 )
	{
		mid = (l+r)/2;
		double tottime =0.0;
		for(int i=0;i<n;i++)
		{
			double x = max(0.0 , mid*(v[i].FF) -v[i].SS);
			tottime+=x;														
		}
		if(tottime>p*mid)
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
	}

	cout<<setprecision(5)<<mid;


}
