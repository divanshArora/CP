
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

int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	ll l = 1,r=(ll)2e18;
	while(l<r)
	{
		ll mid = l+ (r-l)/2;
		ll candies = n;
		ll got = 0;
		while(candies>0)
		{
			ll tx =min(mid,candies);
			got+=tx;
			candies-=tx;
			if(candies>=10)
			{
				tx=(1*candies)/10;
				candies-=tx;
			}
		}
		if(2*got>=n)
		{
			r = mid;
		}
		else
		{
			l = mid+1;
		}
	}
	cout<<r;
}
