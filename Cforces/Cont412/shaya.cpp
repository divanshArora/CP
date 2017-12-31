
using namespace std;
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

typedef vector<ll> vll;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}



int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll x,y,p,q;
		cin>>x>>y>>p>>q;
		if(p==q)
		{
			if(x==y)
			{
				cout<<0<<'\n';continue;
			}
			else
			{
				cout<<-1<<'\n';
			}
		}
		ll ans = 0;
		ll r = 9*((ll)1e17);
		ll l = 0;
		ll mid =-1;
		while(l<r)
		{
			mid = l+ (r-l)/2;
			if(((p%q)*((y + mid)%q))%q==0 && (p*(y+mid))/q>=x)
			{
				r = mid;
			}
			else
			{
				l = mid+1;
			}
		}

		if(mid>=9*((ll)1e17) || mid<=0)
		{
			cout<<-1<<'\n';
		}
		else
		{
			cout<<mid<<'\n';
		}


	}
	return 0;
}
