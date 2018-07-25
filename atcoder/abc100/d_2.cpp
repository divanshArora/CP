
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long 
#define FF first
#define SS second
#define MOD 1000000007

using namespace std;

int gcd(int a, int b) {
  while (a > 0 && b > 0)
    if (a > b) a %= b;
    else b %= a;
  return a + b;
}

ll modpower(ll x, ll y, ll p) //x^y mod p
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y %2!= 0)
            res = (res*x) % p;
 
        // y must be even now
        y = y/2;
        x = (x*x) % p;  
    }
    return res;
}
const int maxn = 1001;
ll x[maxn],y[maxn],z[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector< tuple < ll, ll, ll> > v;
	for(int i=0;i<n;i++)
	{
		ll p,q,r;
		cin>>p>>q>>r;
		v.pb(make_tuple(p,q,r));
	}
	sort(v.begin(),v.end(),less<tuple<ll,ll,ll>>());
	ll ansx = 0, ansy=0,ansz=0;
	for(int i=0;i<m;i++)
	{
		ansx+=get<0>(v[i]);
		ansy+=get<1>(v[i]);
		ansz+=get<2>(v[i]);
	}	
	ll final_ans =0;
	final_ans = max(abs(ansx)+abs(ansy) + abs(ansz),final_ans);
	for(int i=m;i<n;i++)
	{
		ansx+=get<0>(v[i]);
		ansy+=get<1>(v[i]);
		ansz+=get<2>(v[i]);
		ansx-=get<0>(v[i-m]);
		ansy-=get<1>(v[i-m]);
		ansz-=get<2>(v[i-m]);
		final_ans = max(abs(ansx)+abs(ansy) + abs(ansz),final_ans);
	}
	cout<<final_ans<<'\n';
}
